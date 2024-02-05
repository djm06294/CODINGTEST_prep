// 24.02.05 MON
// JOOYOUNG KIM
// https://leetcode.com/problems/range-sum-of-bst/description/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        TreeNode* tmp = root;

        while(tmp!=NULL) {
            if(tmp->val > low) {}
        }
    }

    int recursiveSearchMin(TreeNode* tn, int low) {
        if(tn->val < low && tn->right == NULL) return 0;
        if(tn->val > low && tn->left == NULL) return tn->val;
        
        int sum =0;
        if(tn->val < low) sum = recursiveSearchMin(tn->right, low);
        if(tn->val > low) {
            return tn->val + recursiveSearchMin(tn->left, low);
        }


    }
};