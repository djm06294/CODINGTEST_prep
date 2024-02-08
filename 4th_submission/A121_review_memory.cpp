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