#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/42884


int solution(std::vector<std::vector<int>> routes) {
    int answer = 0;
    std::vector<int> ans;
    sort(routes.rbegin(), routes.rend());

   
    for (int i = 0; i < routes.size(); i++) {
        if (i == 0) {
            ans.push_back(routes[0][0]);
            continue;
        }
        bool flag = 0;
        for (int j = 0; j < ans.size(); j++) {
           
            if (routes[i][0] <= ans[j]&&ans[j] <= routes[i][1]) {
                flag = 1;
                
                break;
            }
        }
        std::cout <<"flag : "<<flag<<"\n";
        if (flag == 0) {
            ans.push_back(routes[i][0]);
        }
    }
    answer = ans.size();
    
    return answer;
}