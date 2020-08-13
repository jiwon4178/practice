#include <string>
#include <vector>
#include <queue>

//using namespace std;

int solution(int bridge_length, int weight, std::vector<int> truck_weights) {
    int answer = 0;
    int bridge_weight = 0;
    int truck_idx = 0;

    std::queue<int> truck_in;
    std::queue<int> ttime;

    for (int i = truck_idx; i < truck_weights.size(); i++) {
        truck_in.push(truck_weights.at(i));
    }

    answer++;
    ttime.push(answer);
    bridge_weight += truck_weights.at(truck_idx);
    truck_idx++;


    while (1) {
        if (ttime.size() == 0) {
            break;
        }
        answer++;

        if (answer - ttime.front() == bridge_length) {
            ttime.pop();
            bridge_weight = bridge_weight - truck_in.front();
            truck_in.pop();
        }
        if (truck_idx == truck_weights.size()) {
            continue;
        }
        if (bridge_weight + truck_weights.at(truck_idx) <= weight) {
            ttime.push(answer);
            bridge_weight += truck_weights.at(truck_idx);
            truck_idx++;
        }



    }

    return answer;
}