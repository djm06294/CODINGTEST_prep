// 문제: 두명이 각자 한개의 캔디 상자를 서로 교환해서 총 캔디수가 서로 동일하게 만들기

// 각각의 총 캔디 수를 먼저 센 후에, binary_search라는 함수를 사용했다. alice의 각 캔디에 대하여 교환 후 총 수를 같게 만드는 bob의 캔디가 존재하는지 찾아보는 식으로 구현했다.

// binary_search는 뭐하는 함수이지? "first 부터 last 까지 주어진 value가 있는지 이진탐색을 통해 찾는다."
// "일반적인 선형 탐색과는 다르게 이진 탐색을 사용하기 때문에 함수가 제대로 작동하기 위해서는 [first, last) 범위의 원소들이 최소한 value 를 기준으로 부분 정렬 되어 있어야만 한다. 다시 말해 아래와 같은 조건을 만족해야 한다."
// https://modoocode.com/325

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sum1=0,sum2=0;
        for(int i=0;i<a.size();i++)
            sum1+=a[i];
        for(int i=0;i<b.size();i++)
            sum2+=b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
            if(binary_search(b.begin(),b.end(),(sum2-sum1)/2+a[i]))
                return {a[i],(sum2-sum1)/2+a[i]};
        return {-1,-1};
    }
};