// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/find-the-difference/description/

#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char answer;
        int alphaCount[26] = {0};
        for(auto c:s) alphaCount[c-'a']++;
        for(auto c:t) alphaCount[c-'a']--;

        for(int i=0; i<26; i++) 
            if(alphaCount[i] != 0) answer = i+'a';

        return answer;
    }
};