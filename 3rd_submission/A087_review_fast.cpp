#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]>b[1];
        });
        int val=0;
        for(int i=0;i<n;i++)
        {
            int x=min(boxTypes[i][0],truckSize);
            val+=x*boxTypes[i][1];
            truckSize-=x;
            if(!truckSize)break;
            cout<<val<<endl;
        }
        return val;
    }
};