// 24.01.16 TUE
// Jooyoung Kim
// https://leetcode.com/problems/summary-ranges/description/

// 좀 더 빠르고 보기 편하게 짤 수도 있엇을거 같음
// 느린편

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> nums) {
        vector<string> answer;
        int st, end;
        for(auto& i: nums) {
            if(i == nums.front()) {      //초기화
                st =  end = i;
                if(i!=nums.back()) continue;
            } 
            
            if(end+1 == i) {
                end++;
            } else {
                if(st == end)
                    answer.push_back(to_string(st));
                else
                    answer.push_back(to_string(st)+"->"+to_string(end));

                st = end = i;
            }

            if(i==nums.back() && i!=nums.front()) {
                if(st == end)
                    answer.push_back(to_string(st));
                else
                    answer.push_back(to_string(st)+"->"+to_string(end));
            }
        }
        return answer;
    }
};

int main() {
    Solution S;
    vector<string> v = S.summaryRanges({-1});
    for(auto& i: v) {
        cout<<i<<endl;
    }

}