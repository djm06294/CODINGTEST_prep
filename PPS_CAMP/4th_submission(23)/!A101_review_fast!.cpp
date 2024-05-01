// 문제: 두명이 각자 한개의 캔디 상자를 서로 교환해서 총 캔디수가 서로 동일하게 만들기

// 

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<200002> bf;
        int sumA = 0, sumB = 0;
        for(auto n: A) {
            sumA += n;
        }
        for(auto n: B) {
            sumB += n;
            bf.set(2*n);
        }
        int diff = sumA - sumB;
        for(auto n: A) {
            int det = 2*n - diff;
            if(det > 0 && det < 200002 && bf.test(det)) {
                return {n, (2*n-diff)/2};
            }
        }
        return {};
    }
};
auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();