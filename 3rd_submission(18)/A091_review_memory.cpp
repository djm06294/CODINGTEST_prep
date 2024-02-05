// 문제: 해당하는 정수를 정수 행렬에서 모두 제거하기.
// 매우 심플하게 구현했다. 메모리 용량이 더 적게 나온다.

// 그냥 val과 일치하지 않으면 행렬의 처음 자리부터 넣어줬다. 매우 간단하네.

#include <iostream>
#include <vector>
using namespace std;

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