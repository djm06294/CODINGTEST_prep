// 문제: 세가지 괄호로 이루어진 string이 valid한지 확인하기.

// 더 빠르다. 원리는 더 간단하다. 하나하나 확인을 해주고 pop하는 건데, 왜 더 빠른건지 모르겠음.

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c:s) {
            if(c=='(' || c=='{' || c=='[') {
                st.push(c);
            } else if(st.empty()) {
                return false;
            } else if(st.top()=='(' && c==')') {
                st.pop();
            } else if(st.top()=='{' && c=='}') {
                st.pop();
            } else if(st.top()=='[' && c==']') {
                st.pop();
            } else {
                return false;
            }
        }
        
        if(st.empty())
            return true;  
        else 
            return false;      
    }
};