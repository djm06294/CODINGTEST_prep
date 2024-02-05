// 24.02.05 MON
// JOOYOUNG KIM
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* intersectNode;
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        vector<int> numbers;

        while(1) {
            numbers.push_back(tmp1->val);
            if(tmp1->val != -1) tmp1->val = -1;
            else {
                intersectNode = tmp1;
                break;
            }

            numbers.push_back(tmp2->val);
            if(tmp2->val != -1) tmp2->val = -1;
            else {
                intersectNode = tmp2;
                break;
            }
        }
        
        tmp1 = headA;
        tmp2 = headB;

        while(!numbers.empty()) {
            headA->val = numbers.front();
            numbers.erase(numbers.begin());
            if(numbers.empty()) break;
            headB->val = numbers.front();
            numbers.erase(numbers.begin());
        }
        

        
    }
};