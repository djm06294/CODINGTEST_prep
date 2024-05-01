// 문제: 두 행렬을 오름차순으로 정렬해서 합치기
// 매우 깔끔하고 알고리즘 적인 코드인듯.
// 가장 빠름 but 메모리 소비 좀 큼. (왠지 모르겠음)

// nums1의 마지막 원소와 nums2의 첫 원소부터 비교를 해서 nums2의 원소보다 큰 애들을 다 nums1에서 오른쪽으로 이동을 시켜두고, while문이 끝난 후 nums2의 원소를 빈자리에 넣어주는 방식이다.
// 이런 생각하기 어려웠을 것 같은데 신기하다.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0; j < n; j++){
            int i = m + j - 1;
            while (i >= 0 && nums1[i] > nums2[j]){
                nums1[i + 1] = nums1[i];
                i--;
            }
            nums1[i + 1] = nums2[j];
        }
        
    }
};