// 24.02.04 SUN
// JOOYOUNG KIM
// https://leetcode.com/problems/remove-element/description/

// fast! good

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int> nums, int val) {  // nums에 & 붙여야 채점가능
        int size = nums.size();
        int answer = size;
        int offset = 0;

        for(int i=0; i+offset<size; i++) {
            nums[i] = nums[i+offset];
            while(nums[i]==val) {
                answer--;
                offset++;
                if(i+offset<size)
                    nums[i] = nums[i+offset];
                else
                    nums[i] = 0;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    s.removeElement({2,2,2,0,0}, 0);
    s.removeElement({0,1,2,2,3,0,4,2}, 2);
}