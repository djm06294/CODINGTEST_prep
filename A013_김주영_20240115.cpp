// 24.01.15 MON
// Jooyoung Kim
// https://leetcode.com/problems/single-number/description/

// very easy 
// 속도가 좀 느림. 빠른 코드는 ^=(XOR)연산자 사용함!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> nums) {
        int tmp;
        sort(nums.begin(), nums.end());

        while(1) {
            tmp = nums.back();
            nums.pop_back();
            if(tmp==nums.back()) nums.pop_back();
            else return tmp;
        } 
    }
};

int main() {
    Solution S;
    cout << S.singleNumber({4,1,2,1,2});
}