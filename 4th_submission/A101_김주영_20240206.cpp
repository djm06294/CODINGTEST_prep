// 24.02.06 TUE
// JOOYOUNG KIM
// https://leetcode.com/problems/fair-candy-swap/description/

// lil slow

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> answer;
        int totAlice = 0, totBob = 0;
        for(auto i:aliceSizes) totAlice += i;
        for(auto i:bobSizes) totBob += i;

        int diff = (totAlice - totBob)/2;   // diff should be even

        for(int i:aliceSizes) {
            for(int j:bobSizes) {
                if(i-j == diff) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }        
    }
};