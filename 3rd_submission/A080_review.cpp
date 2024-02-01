#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //linear time, o 1 space
        int ans=0;
        int cnt=0;
        for(int num:nums){
            if(cnt==0) ans=num;
            
            if(num==ans) cnt++;
            else cnt--;
            
        }

        return ans;
        
    }
};