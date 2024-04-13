// 24.02.08 THU
// JOOYOUNG KIM
// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <stack>
using namespace std;

bool isStringValid(string s) {
    stack<char> st;
    for(auto &c:s) {
        if(c=='(' || c=='[') st.push(c);
        else if(c==')') {
            if(st.empty() || st.top()!='(') 
                return false;
            else
                st.pop();

        } else if(c==']') {
            if(st.empty() || st.top()!='[') 
                return false;
            else
                st.pop();  
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main() {
    // 288ms -> 4ms 됨
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string s;

    while(1) {
        getline(cin, s);
        if(s==".") break;

        if(isStringValid(s)) cout<<"yes\n";
        else cout<<"no\n";
    }        
}