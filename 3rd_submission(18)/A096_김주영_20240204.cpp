// 24.02.04 SUN
// JOOYOUNG KIM
// https://leetcode.com/problems/number-of-1-bits/description/

#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamWeight = 0;
        while(n!=0) {
            if(n%2==1) hamWeight++;
            n = n/2;
        }
        return hamWeight;
    }
};