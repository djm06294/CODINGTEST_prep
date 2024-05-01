// 24.01.25 THU
// JooYoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for_each(s.begin(), s.end(), [](auto& c){c = tolower(c);});
    s[0] = toupper(s[0]);

    int len = s.length();
    for(int i=0; i<len-1; i++)
        if(s[i] == ' ') s[i+1] = toupper(s[i+1]);

    return s;
}


// 윤원준's code
// #include <string>
// #include <vector>

// using namespace std;

// string solution(string s) {
//     string answer = "";

//     answer += toupper(s[0]);
//     for (int i = 1; i < s.size(); i++)
//         s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

//     return answer;
// }