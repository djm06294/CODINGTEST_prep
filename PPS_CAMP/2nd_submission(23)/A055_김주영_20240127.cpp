// 24.01.27 SAT
// JooYoung Kim
// https://leetcode.com/problems/remove-outermost-parentheses/description/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int count=0, len = s.length();
        int stIdx=0, lenCnt=0;

        for(int i=0; i<len; i++) {
            if(s[i]=='(') count++;
            else count--;

            lenCnt++;

            if(count==0) {
                answer += s.substr(stIdx+1, lenCnt-2);
                stIdx = i+1;
                lenCnt = 0;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    cout<<s.removeOuterParentheses("(()())(())");
}