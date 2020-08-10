#include <string>
#include <vector>
//https://programmers.co.kr/learn/courses/30/lessons/12899

std::string solution(int n) {
    std::string answer = "";
    std::vector <std::string> s;
    int tmp = 0;
    int rem;
    
    while(n != 0){
        rem = n % 3;
        tmp = n / 3;
        if(rem == 0){
            s.push_back("4");
            n = tmp-1;
        }
        else if(rem == 1){
            s.push_back("1");
            n = tmp;
        }
        else{
            s.push_back("2");
            n = tmp;
        }
    
    }
    
    for(int j = s.size()-1; j >= 0; j--){        
        answer = answer + s.at(j);
    }
    
    return answer;
}