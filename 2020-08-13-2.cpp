#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/43238


long long solution(int n, std::vector<int> times) {
    long long answer = 0;
     sort(times.begin(), times.end());
    
    long long max = (long long)times.back() * n;        //(long long)을 사용하지 않으면 형변환 제대로 이루어 지지 않은듯
    answer = max;
    long long hnum = 0;
    long long min = 1;
    long long mid = 0;
    while (min <= max) {
        hnum = 0;
        mid = (min + (long long)max) / 2;
        for (long long i=0; i < times.size(); i++) {
            hnum += mid / times[i];
        }
        
        if (hnum >= n) {
            if(mid < answer){
                answer = mid;
            }
            max = mid -1;
        }
        else {
            min = mid + 1;
        }
    }

    return answer;
}