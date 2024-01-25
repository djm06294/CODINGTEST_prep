// 24.01.13 SAT
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12910
// Very Easy

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for(auto& i : arr) {
        if(i%divisor==0) answer.push_back(i);
    }

    if(answer.empty()) {
        answer.push_back(-1);
    } else {
        sort(answer.begin(), answer.end());
    }
    
    // return answer.empty() ? vector<int>(1, -1) : answer;
    // 이런 방법도 있구나.

    return answer;
}

