// 24.01.27 SAT
// JooYoung Kim
// https://leetcode.com/problems/next-greater-element-i/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
        vector<int> answer;

        for(auto& i:nums1) {

            auto it = find(nums2.begin(), nums2.end(), i);
            for(it; it!=nums2.end(); ++it) {
                if(*it > i) {
                    answer.push_back(*it);
                    break;
                }
            }

            if(it == nums2.end()) 
                answer.push_back(-1);
        }

        return answer;        
    }
};

int main() {
    Solution s;
    vector<int> answer = s.nextGreaterElement({4,1,2}, {1,3,4,2});
    for(auto& i:answer) {
        cout<<i<<endl;
    }
}

// 더 빠른 코드! 이해 해보기
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size(), m=nums2.size();
//         vector<int> ans(n, -1);
//         unordered_map<int, int> data;
//         for(int i=0; i<m; i++) data[nums2[i]]=i;
//         for(int i=0; i<n; i++){
//             int val=nums1[i];
//             int index=data[val];
//             for(int j=index+1; j<m; j++){
//                 if(nums2[j]>val){
//                     ans[i]=nums2[j];
//                     break;
//                 }
//             }
//         }
//         return ans;

//     }
// };