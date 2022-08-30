/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* next;
        ListNode* curr=head;
        while(curr->next!=NULL){
            if(curr->val==curr->next->val){
                next=curr->next->next;
                delete(curr->next);
                curr->next=next;
            }
            else curr=curr->next;  //if next el is not same simply move curr
        }
        return head;
    }
};