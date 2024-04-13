// 문제: 최대의 같은 숫자의 개수를 degree라고 할때, 동일한 degree를 유지하는 최소 길이의 subarray 길이 구하기. 행렬의 구성(순서)는 변하지 않는다.

// 와.. 모르겠다 잘짠 코드인지 모르겠지만 정말 하나하나 써보기 전까지는 무슨 말인지 이해하기 너무 어려웠다.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto x:nums){
            mp[x]++;
        }

        int mxf=0;
        for(auto p:mp){
            mxf=max(mxf,p.second);
        }

       int i=0,j=0;
       unordered_map<int,int>fmp;
       int mx=0;
       int ans=INT_MAX;
       while(j<nums.size()){
          fmp[nums[j]]++;
          while(fmp[nums[j]]==mxf){
              ans=min(ans,(j-i+1));
              fmp[nums[i]]--;
              i++;
          }
          j++;
          
       }

       return ans;

    }
};