// 문제: 해당하는 정수를 정수 행렬에서 모두 제거하기.
// 매우 심플하게 구현했다. 메모리 용량이 더 적게 나온다.

// val인 경우 그냥 vector 함수 erase를 사용했다! erase는 많이 하면 코드가 느려질 수 있다고 들었는데, 그래도 원소를 하나하나 이동하는 것 보다는 훨씬 빠른가보다.. 

// <bits/stdc++.h>는 어떤 헤더파일인지 궁금하다.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==val){
              nums.erase(nums.begin()+i);
              n--;
            }
          else{
            i++;
          }
        }
      return n;
    }
};