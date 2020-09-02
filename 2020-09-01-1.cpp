#include <string>
#include <vector>
#include <algorithm>
 
//https://programmers.co.kr/learn/courses/30/lessons/12938
 
std::vector<int> solution(int n, int s) {
    std::vector<int> answer;
    int x = s/n;
    int y = s%n;
    if (x == 0) {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0; i < n-y; i++) {
        answer.push_back(x);
    }
    for (int i = 0; i < y; i++) {
        answer.push_back(x+1);
    }
    return answer;
}
