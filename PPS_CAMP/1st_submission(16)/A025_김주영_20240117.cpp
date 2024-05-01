// 24.01.17 FRI
// Jooyoung Kim
// https://leetcode.com/problems/power-of-four/description/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        float tmp = sqrt(n);
        // cout<<"sqrt"<<tmp<<endl;
        if(tmp-(int)tmp == 0 && (int)tmp%2 == 0) {
            return true;
        }
        
    }
};

int main() {
    int k;
    cin>>k;
    Solution s;
    s.isPowerOfFour(k);
}