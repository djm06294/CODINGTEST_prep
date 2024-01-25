// 24.01.26 FRI
// JooYoung Kim
// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int count = 0;
        for(int i=0; i<len/2; i++) {
            char tmp = s[i];
            if(tmp==65 || tmp==69 || tmp==73 || tmp==79 || tmp==85 || tmp==97 || tmp==101 || tmp==105 || tmp==111 || tmp==117) count++;
        }
        for(int i=len/2; i<len; i++) {
            char tmp = s[i];
            if(tmp==65 || tmp==69 || tmp==73 || tmp==79 || tmp==85 || tmp==97 || tmp==101 || tmp==105 || tmp==111 || tmp==117) count--;
        }

        if(count==0) return true;
        else return false;        
    }
};