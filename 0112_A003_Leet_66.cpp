// 24.01.12 FRI
// Jooyoung Kim
// https://leetcode.com/problems/plus-one/

// 런타임 조금 느린편

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt9 = 0;

        // + empty()인지 항상 확인해주기!!!
        while (!digits.empty() && digits.back() == 9) {
            cnt9++;
            digits.pop_back();
        }

        if (digits.empty()) {
            digits.push_back(1);
        } else {
            int tmp = digits.back();
            digits.pop_back();
            digits.push_back(tmp + 1);
        }

        while (cnt9--) {
            digits.push_back(0);
        }

        return digits;
    }
};


int main() {
    Solution sol;
    vector<int> v = {9,9,9};
    v = sol.plusOne(v);
    while(0) {
        cout << "hi";
    }

    for(auto& i : v) {
        cout<<i<< " "; 
    }
}