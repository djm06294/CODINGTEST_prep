// 24.01.26 FRI
// JooYoung Kim
// https://leetcode.com/problems/student-attendance-record-i/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int cntA=0, cntL=0, len = s.length();
        for(int i=0; i<len; i++) {
            if(s[i] == 'A') cntA++;
            if(s[i] == 'L') cntL++;
            else cntL=0;

            if(cntA >= 2) return false;
            if(cntL >= 3) return false;
        }
        return true;        
    }
};