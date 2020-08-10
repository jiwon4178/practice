#include <string>
#include <vector>

//https://programmers.co.kr/learn/courses/30/lessons/42586

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {
    std::vector<int> answer;
    
    std::vector<int> day;
    int tmp = 0;
    //int rem = 0;
    
    for (int i = 0; i < progresses.size(); i++){
        tmp = 100 - progresses.at(i);       //남은 작업량
        if(tmp % speeds.at(i) == 0){        //남은 작업량이 나눠떨어지는경우
            day.push_back(tmp / speeds.at(i));
        }
        else{                               //남은 작업량이 나눠떨어지지 않는 경우
            day.push_back(tmp / speeds.at(i) +1);
        }
    }
    
    
    int cnt = 0;    //하루에 배포하는 작업수
    int start = 0;  //배포시작하는 작업
    for (int j = 0; j < day.size(); j++){
        cnt++;
        if(j == day.size()-1){      //마지막 작업인경우
            answer.push_back(cnt);
            continue;
        }
        if(day.at(j+1)>day.at(start)){      //배포 시작하는 작업보다 필요로하는 작업날짜가 큰경우 그 이전작업까지만 배포함
            answer.push_back(cnt);          
            cnt = 0;
            start = j+1;                    //그리고 배포시작하는 작업위치 변경
        }
        
    }
    return answer;
}