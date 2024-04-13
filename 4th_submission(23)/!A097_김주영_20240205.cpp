// 24.02.05 MON
// JOOYOUNG KIM
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        const int size = numbers.size();

        for(int i=0; ; i++) {
            int tmp = target - numbers[i];
            for(int j=i+1; j<size; j++) {
                if(numbers[j] == tmp) {
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    return answer;
                }
            }
        }
    }
};