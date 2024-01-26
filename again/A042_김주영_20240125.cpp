// 24.01.25 THU
// JooYoung Kim
// https://leetcode.com/problems/backspace-string-compare/

// slow, 검토해보고 싶음

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        if(!delete_sharps(s).compare(delete_sharps(t)))
            return true;
        else
            return false;        
    }

    string delete_sharps(string s) {
        // cout<<"**"<<s<<endl;
        while(1) {
            int idx = s.find('#');
            if(idx == string::npos) break;

            if(idx == 0) {
                s = s.substr(idx+1);
            } else {
                s = s.substr(0, idx-1) + s.substr(idx+1);
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    string str = "abc";
    cout<<"["<<str.substr(3)<<"]";
    // cout<< s.backspaceCompare("ab#c", "ad#c");
}

// #
// #