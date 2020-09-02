#include <string>
#include <vector>
#include <algorithm>
#include <queue>
//https://programmers.co.kr/learn/courses/30/lessons/49189

int solution(int n, std::vector<std::vector<int>> edge) {
    int answer = 0;
    std::vector<int> dv(n,0);  // 거리에 따른 개수 기록용
    
    // 반대 간선도 넣기
    int s = edge.size();
    for(int i=0;i<s;i++){
        std::vector<int> temp;
        temp.push_back(edge[i][1]);
        temp.push_back(edge[i][0]);
        edge.push_back(temp);
    }
    
    sort(edge.begin(), edge.end()); // 출발 정점 기준 정렬
    std::vector<bool> check(n+1); // 방문 체크용
    
    // bfs를 통해 가장 먼 거리의 노드들 추가
    std::queue<std::pair<int,int>> q; // index, 거리
    q.push(std::pair<int,int>(1,1));
    check[1] = true; // visit
    
    // BFS
    while(!q.empty()){
        std::pair<int,int> now_p = q.front();
        int now = now_p.first; // 현재 경로
        int now_d = now_p.second; // 현재 거리
        q.pop();
        // 갈 수 있고 가지 않은 곳들 추가
        for(int i=0;i<edge.size();i++){
            if(edge[i][0] == now && !check[edge[i][1]]){
                q.push(std::pair<int,int>(edge[i][1], now_d+1));
                check[edge[i][1]] = true; // visit
                dv[now_d]++; // 거리마다 기록
            }
        }
    }
    
    // 가장 멀리 떨어져 있는 노드 수
    reverse(dv.begin(), dv.end());
    for(int i=0;i<dv.size();i++)
        if(dv[i]!=0)
            return dv[i];
}