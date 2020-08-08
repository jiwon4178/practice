
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

//using namespace std;

int solution(std::vector<int> priorities, int location) {
    int answer = 0;
    
    std::queue<std::pair<int, int>> que; //2차원 큐
    std::priority_queue<int> que2; //우선순위 큐
    for (int i = 0; i < priorities.size(); i++){
        que.push(std::make_pair(i, priorities[i]));
        que2.push(priorities[i]);
    }
    
    while(!que.empty()){	
        if (que.front().second == que2.top()){
            if (que.front().first == location){ // 원하는 위치에 있던 숫자인경우
                return answer + 1;
            }
            else {
                answer++;
                que.pop(); que2.pop();
            }
        }
        else {
            que.push(que.front());
            que.pop();
        }
    }
    return answer;
}