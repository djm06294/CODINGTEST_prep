// 24.02.05 MON
// JOOYOUNG KIM
// https://leetcode.com/problems/valid-parentheses/description/

// A128이랑 비슷한 문제.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c:s) {
            if(c=='(') {
                st.push(c+1);   // push ')'
            } else if(c=='{' || c=='[') {
                st.push(c+2);   // push '}'or']'
            } else if(st.empty()) {
                return false;
            } else if(st.top() != c) {
                return false;
            } else {
                st.pop();
            }
        }
        if(st.empty())
            return true;  
        else 
            return false;      
    }
};

int main() {
    Solution s;
    cout<<s.isValid("{[]}");
}