// 24.02.04 SUN
// JOOYOUNG KIM
// https://leetcode.com/problems/sort-array-by-parity-ii/description/

// fast good

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findOdd(vector<int>& V, int curr) {
        for(curr; curr<V.size(); curr++)
            if(V[curr]%2 == 1) return curr;
        return -1;
    }

    int findEven(vector<int>& V, int curr) {
        for(curr; curr<V.size(); curr++)
            if(V[curr]%2 == 0) return curr;
        return -1;
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();

        for(int i=0; i<size; i+=2) {
            if(nums[i]%2 != 0) {
                int even_idx = findEven(nums, i);
                int tmp = nums[i];
                nums[i] = nums[even_idx];
                nums[even_idx] = tmp;
            }

            if(nums[i+1]%2 == 0) {
                int odd_idx = findOdd(nums, i+1);
                int tmp = nums[i+1];
                nums[i+1] = nums[odd_idx];
                nums[odd_idx] = tmp;
            }
        }
        return nums;        
    }
};