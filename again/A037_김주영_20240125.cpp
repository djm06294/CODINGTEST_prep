// 24.01.25 THU
// JooYoung Kim
// https://leetcode.com/problems/sqrtx/description/

// sloww
// 사용법: ./filename number

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long i;
        for(i=1; i*i<=x; i++) {}
        return i-1;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    cout<< s.mySqrt(*argv[1] - '0');
}