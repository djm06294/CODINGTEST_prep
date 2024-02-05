// 24.02.03 SAT
// JOOYOUNG KIM
// https://leetcode.com/problems/maximum-units-on-a-truck/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compareUnits(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int totUnits = 0, totBox = 0;

        sort(boxTypes.begin(), boxTypes.end(), compareUnits);

        for(auto box:boxTypes) {
            while(box[0]!=0 && truckSize>totBox) {
                totUnits += box[1];
                box[0]--;
                totBox++;
            }
        }
        return totUnits;        
    }
};
