#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==val){
              nums.erase(nums.begin()+i);
              n--;
            }
          else{
            i++;
          }
        }
      return n;
    }
};