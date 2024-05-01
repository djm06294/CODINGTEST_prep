// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/move-zeroes/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i=0, idx=0;

        for(; idx<size; i++, idx++) {
            while(idx<size && nums[idx]==0) idx++;
            if(idx>=size) break;

            nums[i] = nums[idx];
        }

        for(i; i<size; i++) nums[i]=0;        
    }
};

int main() {
    Solution s;
    vector<int> v = {0,1,0,3,12};
    s.moveZeroes(v);
}