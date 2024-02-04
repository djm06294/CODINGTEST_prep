// 매우 심플하게 구현했다. 메모리 용량이 더 적게 나온다.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pointer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[pointer++] = nums[i];
            }
        }
        return pointer;
    }
};