// 24.01.27 SAT
// JooYoung Kim
// https://leetcode.com/problems/reverse-linked-list/description/

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head;
        ListNode* tmp2 = head->next;
        int size = 1;
        while(tmp != nullptr) {
            tmp = tmp->next;
            size++;
        }
        if(size=1) return head;
        

        tmp = head;
        for(int i=0; ;i++) {
            int num = tmp->val;
            tmp->val = tmp2->val;
            tmp2->val = num;

            tmp = tmp->next;
            tmp2 = tmp2->next;

            if(tmp2 == nullptr) {
                tmp = head;
                tmp2 = head->next;
                i = 0;
                size--;
                if(size == 1) break;
            }
        }
        return head;        
    }
};