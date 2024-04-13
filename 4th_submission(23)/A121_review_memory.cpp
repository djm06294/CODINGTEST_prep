// 문제: 최대의 같은 숫자의 개수를 degree라고 할때, 동일한 degree를 유지하는 최소 길이의 subarray 길이 구하기. 행렬의 구성(순서)는 변하지 않는다.

// unordered_map을 사용해서 모든 숫자와 갯수를 저장해준다. 그리고 가장 빈번하게 나온 수의 첫 등장과 마지막 등장을 구한다. 모든 가장 빈번하게 나온 수에 대해 이런 작업을 하고 그 중 첫 등장과 마지막 등장 텀이 가장 짧은 것을 리턴한다.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxFreq = 0;

        // find maximum frequency
        for(auto x : nums){
            m[x]++;

            if(m[x] > maxFreq){
                maxFreq = m[x];
            }
        }

        if(maxFreq == 1){
            return 1;
        }

        // for all element with frequency = maxFreq, find length
        int ans = INT_MAX;
        for(auto x : m){
            if(x.second == maxFreq){
                // find 1st and last occurance
                int l = 0, h = nums.size()-1 , first = 0, last = 0;
                int n = nums.size();

                // first 
                for(int i = 0; i < n; i++){
                    if(x.first == nums[i]){
                        first =  i;
                        break;
                    }
                }

                // last
                for(int i = n-1; i >= 0; i--){
                    if(x.first == nums[i]){
                        last =  i;
                        break;
                    }
                }

                int len = last - first + 1;
                ans = min(ans,len);
            }
        }

        return ans;
    }
};