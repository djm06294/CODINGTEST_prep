// 24.02.03 SAT
// JOOYOUNG KIM
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// Balanced Tree? AVL ? red-black?
// 아니면 sorted된 점을 이용해야하나

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();


        
        
    }

    TreeNode* recursiveMakeTree(vector<int>* nums) {


    }


};