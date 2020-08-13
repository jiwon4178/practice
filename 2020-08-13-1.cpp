#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

//https://programmers.co.kr/learn/courses/30/lessons/42839

bool isPrime(int num) {
    bool prime = true;  

    if (num < 2) {
        return false;
    }

    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}

int solution(std::string numbers) {
    int answer = 0;
    std::vector <int> num;
    for (int i = 0; i < numbers.size(); i++) {
        num.push_back(numbers[i] - '0');
        //std::cout << snum;
    }

    sort(num.begin(), num.end());
    
   // std::cout << "num size : " << num.size()<<"\n";

    std::vector <int> ans;
    do {
        for (int j = 0; j <= num.size(); j++) {
            int tmp = 0;
            for (int k = 0; k < j; k++) {
                tmp = (tmp * 10) + num[k];
                ans.push_back(tmp);
            }
        }
    } while (next_permutation(num.begin(), num.end()));


    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());


    for (int i = 0; i < ans.size(); i++) {
       // std::cout << ans[i] << "\n";
        if (isPrime(ans[i]) == true) {
            answer++;
        }
    }
//    std::cout << "ans size : " << ans.size() << "\n";

    return answer;
}