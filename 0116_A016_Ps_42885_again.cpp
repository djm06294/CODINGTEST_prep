// 24.01.16 TUE
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/42885

// 시간초과 때문에 거의 찾아보고 품
//https://hwan-shell.tistory.com/200

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0;
    sort(people.begin(), people.end());

    while(idx < people.size()) {
        if(people[idx]+people.back() <= limit) {
            idx++;
        }
        answer++;
        people.pop_back();
    }
    return answer;
}

int main() {
    cout<< solution({70, 50, 80, 50}, 100);
}