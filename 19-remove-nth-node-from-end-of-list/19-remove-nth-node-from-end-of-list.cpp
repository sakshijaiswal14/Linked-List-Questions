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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL) return NULL;
    ListNode *mainn=head;
    ListNode *ref=head;
    for(int i=1;i<=n;i++){
        ref=ref->next;  //move the ref node upto n times
    }
    if(ref==NULL) return head->next;   //nth node is first node
    while(ref->next!=NULL){    //until the ref is null move both ref and mainn
        ref=ref->next;
        mainn=mainn->next;
    }          
    mainn->next=mainn->next->next;  //mainn is the node before given nth node
    return head;
}
};