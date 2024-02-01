// 24.02.01 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/majority-element/description/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int minimum = nums.size() /2;
        if(nums.size()%2 == 0) minimum++;

        sort(nums.begin(), nums.end());
        return nums[minimum];        
    }
};