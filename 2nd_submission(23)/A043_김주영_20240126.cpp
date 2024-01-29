// 24.01.26 FRI
// JooYoung Kim
// https://leetcode.com/problems/longest-common-prefix/

// slow,,,

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        string compStr = strs.front();
        for(auto& str:strs) {
            int i=0, j=0;
            int len = str.length();
            int compLen = compStr.length();

            while(i<len, j<compLen) {
                if(str[i] != compStr[j]) break;
                i++; j++;
            }

            if(i==0) return "";
            compStr = str.substr(0,i);
        }

        return compStr;        
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    cout<<s.longestCommonPrefix({"dog","racecar","car"});
}