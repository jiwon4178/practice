#include <string>
#include <vector>

//https://programmers.co.kr/learn/courses/30/lessons/49993

int solution(std::string skill, std::vector<std::string> skill_trees) {
    int answer = 0;
    int cnt = 0;
    int tmp = 0;
    int loc = 0;
    bool flag = true;
    for(int i = 0; i < skill_trees.size(); i++){
        flag = true;
        tmp = 0;
        for(int j = 0; j < skill_trees.at(i).size(); j++){
            cnt = 0;
            loc = skill.find(skill_trees.at(i).at(j));
            if(loc == -1){
                continue;
            }
            else{
                if(tmp++ != loc){
                    flag = false;
                    break;
                }
            }
          
            
        }  
        if(flag == true){
            answer++;
        }
    }
    
    
    return answer;
}