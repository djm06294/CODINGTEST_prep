// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/degree-of-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 24.02.08 THU
// JOOYOUNG KIM
// https://leetcode.com/problems/degree-of-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<pair<int,int>> degrees;
        int size = nums.size();
        int minLen = size==0 ? 0 : size;

        for(auto i:nums) {
            bool check=1;
            for(auto &j:degrees) {      // & 없으면 second값이 바뀌질 않음. 복사해서 사용하나봄.
                if(j.first == i) {
                    j.second++;
                    check = 0;
                    break;
                }
            }
            if(check==1) degrees.push_back(make_pair(i, 1));
        }

        sort(degrees.begin(), degrees.end(), [](const pair<int,int>& a, const pair<int,int>& b) { return a.second > b.second; });

        int degree = degrees[0].second;

        for(auto p:degrees) {
            int i, j;
            if(p.second != degree) break;

            for(i=0; i<size; i++)
                if(nums[i]==p.first) break;
            
            for(j=size-1; j>=0; j--) 
                if(nums[j]==p.first) break;
            
            if(j-i+1 < minLen) minLen = j-i+1;
        }

        return minLen;      
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,2,3,1};
    cout<<s.findShortestSubArray(v);
}