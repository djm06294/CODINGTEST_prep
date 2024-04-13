// 문제: 0과 자연수가 섞여있는 행렬에서 모든 0을 뒤로 보내기.

// 행렬의 첫 0과 그 이후 첫 0이 아닌 숫자의 인덱스를 구해서 swap하고 차례로 다음 0과 0이 아닌 숫자의 인덱스를 구하고 반복한다.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fir0 = nums.size();
        int firNon0 = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                fir0 = i;
                break;
            }
        }
        for (int i = fir0 + 1; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                firNon0 = i;
                break;
            }
        }
        while (fir0 < nums.size() && firNon0 < nums.size()) {
            nums[fir0] = nums[firNon0];
            nums[firNon0] = 0;
            while (fir0 < nums.size()) {
                if (nums[fir0] == 0) {
                    break;
                }
                ++fir0;
            }
            while (firNon0 < nums.size()) {
                if (nums[firNon0] != 0) {
                    break;
                }
                ++firNon0;
            }
        }
    }
};