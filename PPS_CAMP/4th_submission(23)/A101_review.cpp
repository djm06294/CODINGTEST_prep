// 문제: 두명이 각자 한개의 캔디 상자를 서로 교환해서 총 캔디수가 서로 동일하게 만들기

// 정직하게 문제가 풀라고 말하는 그 알고리즘 대로 짠 코드로 이해된다.
// 먼저 alice와 bob의 총 캔디 갯수를 세고, 각 캔디 박스를 정렬한 다음 하나씩 교환하여본다. 그리고 교환 후 alice와 bob의 캔디 개수 중 무엇이 더 큰지를 확인해서 해당하는 idx를 이동시켜 다시 교환을 시도해본다.
// 교환 후 캔디 수가 같으면 답을 return한다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> answer;
        int sumAlice = 0, sumBob = 0;
        for (int i = 0; i < aliceSizes.size(); i++)
            sumAlice += aliceSizes[i];
        for (int i = 0; i < bobSizes.size(); i++) {
            sumBob += bobSizes[i];
        }
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int ai = 0, bi = 0;
        while (ai < aliceSizes.size() && bi < bobSizes.size()) {
            int b_el = bobSizes[bi], a_el = aliceSizes[ai];
            int tmp_a = sumAlice - a_el + b_el;
            int tmp_b = sumBob - b_el + a_el;
            
            if (tmp_a == tmp_b)
                return {a_el, b_el};
            else if (tmp_a < tmp_b)
                bi++;
            else
                ai++;
        }
        return answer;
    }
};