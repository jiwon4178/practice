#include <string>
#include <vector>
//using namespace std;

std::vector<int> solution(std::vector<int> prices) {
    
   std::vector<int> answer;
    
    int length = prices.size();
    for (int ii = 0; ii < length - 1; ii++) { 

        int count = 0;
        for (int jj = ii + 1; jj < length; jj++) {
            if (prices[ii] <= prices[jj]) { count++; } // 주식의 가격이 크거나 같은 경우
            else { count++; break; } // 주식의 가격이 떨어졌을 경우
        }
        
        answer.push_back(count);
    }
    
    answer.push_back(0);
    
    return answer;
}