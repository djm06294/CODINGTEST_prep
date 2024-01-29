// 24.01.28 SUN
// JooYoung Kim
// https://leetcode.com/problems/height-checker/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        int size=heights.size();
        int count=0;

        for(auto& i:heights)
            expected.push_back(i);
        
        sort(expected.begin(), expected.end());

        for(int i=0; i<size; i++)
            if(heights[i] != expected[i]) 
                count++;
        
        return count;        
    }
};

// 이 코드랑 뭐가 다르길래 메모리 사용량이 차이나지?
// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {
//         vector<int> expected (heights.size());
//         copy(heights.begin(), heights.end(), expected.begin());
//         sort(heights.begin(), heights.end());

//         int diff = 0;
//         for (int i = 0; i < heights.size(); ++i)
//         {
//             if (heights[i] != expected[i]) ++diff;
//         }

//         return diff;
//     }
// };