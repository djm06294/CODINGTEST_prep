// 매우 깔끔하고 알고리즘 적인 코드인듯.
// 가장 빠름 but 메모리 소비 좀 큼.
 
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