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