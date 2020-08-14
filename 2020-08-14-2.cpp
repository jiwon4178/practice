#include <string>
#include <vector>
#include <iostream>
//https://programmers.co.kr/learn/courses/30/lessons/12900

//dp알고리즘 사용??ㅇㅇ

int solution(int n) {
    int answer = 0;
    std::vector<int> dp ;
    dp.push_back(1);
    dp.push_back(2);
    if(n == 1){
        return dp[0];
    }
    else if (n == 2){
        return dp[1];
    }
    int tmp1 = 0, tmp2 = 0;
    for(int i = 2; i < n; i++){
        tmp1 = dp[i-2]+dp[i-1];
        tmp1 = tmp1 % 1000000007;
        dp.push_back(tmp1+tmp2);
    }
    answer = dp.back();
    
    return answer;
}