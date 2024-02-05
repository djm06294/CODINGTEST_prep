// 24.02.04 SUN
// JOOYOUNG KIM
// https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1;

        while(1) {
            if(nums1[i] > nums2[j]) {
                nums1[i+j+1] = nums1[i];
                i--;
            } else {
                nums1[i+j+1] = nums2[j];
                j--;
            }

            if(i<0) {
                while(j>=0) {
                    nums1[i+j+1] = nums2[j];
                    j--;
                }
                return;
            }

            if(j<0) {
                while(i>=0) {
                    nums1[i+j+1] = nums1[i];
                    i--;
                }
                return;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    s.merge(a, 3, b, 3);

    for(auto i:a) cout<<i<<endl;
}