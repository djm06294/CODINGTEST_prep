#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){return a[1] > b[1];});
        int ans = 0;
        for(vector<int>& vec: boxTypes){
            int curr_num = min(truckSize, vec[0]);
            ans += curr_num*vec[1];
            truckSize -= curr_num;
            if(truckSize == 0) break;
        }
        return ans;
    }
};