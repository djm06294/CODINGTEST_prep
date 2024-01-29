// 24.01.29 MON
// JooYoung Kim
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        cout<<s<<endl;
        int len = s.length();
        bool found=true;
        int i;
        while(len && found) {
            found = false;
            for(i=0; i<len-1; i++) {
                cout<<s[i]<< " "<<s[i+1]<<endl;
                if(s[i]==s[i+1]) {
                    cout<<s[i]<< " "<<s[i+1]<<endl;
                    int j=i;
                    for(j; j<len-2; j++) {
                        s[j] = s[j+2];
                    }
                    s.pop_back();
                    s.pop_back();
                    len-=2;
                    found = true;
                    cout<<s<<endl;
                    break;
                }
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    string str = s.removeDuplicates("aababaab");

    cout<<"["<<str<<"]";
}