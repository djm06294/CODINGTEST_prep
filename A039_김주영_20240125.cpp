// 24.01.25 THU
// JooYoung Kim
// https://leetcode.com/problems/valid-perfect-square/description/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        unsigned long i=1;
        while(i*i<num) {
            i++;
        }

        if(i*i==num) return true;
        else return false;       
    }
};