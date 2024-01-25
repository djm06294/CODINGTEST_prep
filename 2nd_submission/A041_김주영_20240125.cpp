// 24.01.25 THU
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for_each(s.begin()+1, s.end(), [](auto& c){c = tolower(c);});
    s[0] = toupper(s[0]);
    return s;
}