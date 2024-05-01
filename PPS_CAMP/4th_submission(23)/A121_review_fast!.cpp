// 문제: 최대의 같은 숫자의 개수를 degree라고 할때, 동일한 degree를 유지하는 최소 길이의 subarray 길이 구하기. 행렬의 구성(순서)는 변하지 않는다.

// 행렬에 등장하는 모든 숫자의 첫 등장 idx와 마지막 등장 idx, 그리고 등장한 횟수를 모두 각각의 unordered_map에 저장을 해주고, 등장 횟수가 최대인 애들만 그 텀을 계산해 최소값을 나타내는 애를 리턴해줬다. 
// 모두 맵에 저장하니까 코드가 훨씬 간단해졌다.(이해하기 쉬워졌다)

// unordered_map은 어떤 경우에 쓰는 것인지 궁금하다! 자료구조의 특징을 더 잘 알아야겠다.

#include <unordered_map>
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> first, count, last;
        for(int i=0;i<nums.size();i++)
        {
            if(first.count(nums[i])==0) first[nums[i]]= i;
            count[nums[i]]++;
            last[nums[i]]=i;
            
        }
        // find degree
        int deg =0;
        for(auto it : count)
        {
            deg = max(deg,it.second);
        }
        // find answer
        int ans = nums.size();
        for( auto it : count)
        {
            if(it.second==deg)
            {
                ans = min(ans, last[it.first]-first[it.first]+1);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        int degree = 0;

        // TWO WAYS TO ITERATE IN A MAP :- 1 USING "->" AND 2. USING "." OPERATOR
        // 1st WAY using "->"
        for(auto it=mp.begin();it!=mp.end();it++){
            degree = max(degree,int(it->second.size()));
            cout<<it->second.size()<<endl;
        }
        int shortestSub = nums.size();
        // 2nd WAY using "."
        for (auto it:mp) {
            if (it.second.size() == degree) {
                shortestSub = min(shortestSub, it.second.back() - it.second[0] + 1);
            } 
        }
        return shortestSub;
    }
};
        // To find the degree of vector nums 
        // int deg;
        // unordered_map<int ,int> mpp;
        // for(int i=0;i<nums.size();i++){
        //     deg= max(deg, ++mpp[nums[i]]);
        // }
        // return deg;


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,int> > mp;
        int ct = 0;
        int degree = 0;
        int out = INT_MAX;
        for(auto it : nums){
            mp[it] = (mp.find(it) == mp.end()) ? make_pair(1, ct) : make_pair(mp[it].first + 1, ct);
            degree = max(degree,mp[it].first);
            ++ct;
        }
        ct = 0;
        for(auto it : nums){
            if(mp.find(it) != mp.end() && mp[it].first == degree){
                out = min(mp[it].second - ct + 1,out);
                mp.erase(it);
            }
            ++ct;
        }

        return out;
    }
};