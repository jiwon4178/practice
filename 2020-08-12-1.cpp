#include <string>
#include <vector>
#include <math.h>
//https://programmers.co.kr/learn/courses/30/lessons/42842
 
std::vector<int> solution(int brown, int red) {
    std::vector<int> answer;
    int sum=brown+red;
    int limit=(int)sqrt(sum);
    
    for(int i=3; i<=limit; i++)
    {
        if(sum % i ==0)
        {
            int tmp = sum/i;
            if((tmp-2) * (i-2) == red)
            {
                answer.push_back(tmp);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}
