// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/maximum-number-of-balloons/description/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int alphaCount[26] = {0};
        int answer=0;

        for(auto c:text)
            alphaCount[c-'a']++;

        while(1) {
            if(alphaCount[0]>0)     // 'a'
                alphaCount[0]--;
            else 
                break; 
                
            if(alphaCount[1]>0)     // 'b'
                alphaCount[1]--;
            else 
                break;            

            if(alphaCount[11]>1)    // 'l'
                alphaCount[11]-=2;
            else 
                break;

            if(alphaCount[13]>0)    // 'n'
                alphaCount[13]--;
            else 
                break;

            if(alphaCount[14]>1)    // 'o'
                alphaCount[14]-=2;
            else 
                break;            

            answer++;
        }
        return answer;
    }
};