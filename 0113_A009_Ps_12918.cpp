// 24.01.13 SAT
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12918

// Very Easy

#include <string>

using namespace std;

bool solution(string s) {
    if(s.length()!=4 && s.length()!=6) 
        return false;

    for(auto& c:s)
        if(c>64) return false;

    return true;
}