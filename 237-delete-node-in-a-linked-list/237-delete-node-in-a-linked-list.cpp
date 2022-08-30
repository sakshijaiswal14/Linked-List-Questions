/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int data=node->next->val;
        node->val=data;
        ListNode* next=node->next->next;
        delete(node->next);
        node->next=next;
    }
};