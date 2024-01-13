// 24.01.13 SAT
// Jooyoung Kim
// https://school.programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

int findChar(string s, char c) {
    int idx = -1, count=0;
    cout << endl << "string is " << s << endl;

    while(s.find(c, idx+1) != string::npos) {
        idx = s.find(c, idx+1);
        count++;
        cout << c << " found at " << idx << endl;
    }

    return count;
}

bool solution(string s)
{
    bool answer = findChar(s, 'p') + findChar(s, 'P') == findChar(s, 'y') + findChar(s, 'Y');

    return answer;
}

int main() {
    cout << solution("pPoooyY") << endl;
}
