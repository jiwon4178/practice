#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
 
//https://programmers.co.kr/learn/courses/30/lessons/42628
//set을 이용한 풀이
std::vector<int> solution(std::vector<std::string> operations) {
    std::multiset<int> mset;
    for (auto o : operations) {
        std::string a = o.substr(0, 1);//앞의 문자 확인
        int num = atoi(o.substr(2).c_str());//뒤의 숫자 확인
        //앞문자가 I(대문자 i) 라면 데이터 넣기
        if (a == "I")     mset.insert(num);
        //I가 아니고 이 비어있지 않다면 최댓값 혹은 최솟값 제거
        else if (!mset.empty()) {
            if (num == 1)    mset.erase(--mset.end());
            else    mset.erase(mset.begin());
        }
    }
    //멀티셋이 비어있다면 0,0 반환
    if (mset.empty())    return { 0 , 0 };
    //비어있지 않다면 최댓값 최솟값 반환
    else    return { *--mset.end() , *mset.begin() };
}
