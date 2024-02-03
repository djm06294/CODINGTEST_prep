// 24.02.03 SAT
// JOOYOUNG KIM
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// slow & large

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> nums) {
        int size = nums.size();
        int dupNum=0;
        for(int i=1; i<size; i++) {
            if(nums[i-1] != nums[i]) continue;

            for(int j=i; j<size; j++)
                nums[j-1] = nums[j];

            dupNum++;
            size--;
        }

        for(auto&i:nums)cout<<i<<endl;

        return dupNum;       
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        for(int i=1 ; i<nums.size() ; i++) {
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};