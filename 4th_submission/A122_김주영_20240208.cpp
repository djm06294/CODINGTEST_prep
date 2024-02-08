// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/rotate-string/description/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int T=1;
        string tmp = goal;
        while(tmp.find(goal[0]) != string::npos) {
            T++;
            tmp = tmp.substr(tmp.find(goal[0])+1);
            cout<<"tmp "<<tmp<<" T"<<T<<endl;
        }

        while(T--) {
            if(s==goal) return true;

            int i = s.substr(1).find(goal[0]);
            s = s.substr(i+1) + s.substr(0, i+1);
            cout<<s<<" "<<i<<endl;
        }

        return false;        
    }
};

int main() {
    Solution s;
    cout<<s.rotateString("abcde", "cdeab");

}