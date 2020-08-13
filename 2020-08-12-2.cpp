#include <iostream>
#include <vector>
#include <set>
#include <cmath>

//https://programmers.co.kr/learn/courses/30/lessons/12913

int max_check(std::vector<int>& v, int idx){
    int temp = 0;
    for(int i = 0; i < 4; i++)
        if(i != idx)
            temp = std::max(temp, v[i]);
    return temp;
}

int solution(std::vector<std::vector<int> > land)
{
    int answer = 0;
    for(size_t i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            land[i][j] += max_check(land[i - 1], j);
            answer = std::max(answer, land[i][j]);
        }
    }
    return answer;
}