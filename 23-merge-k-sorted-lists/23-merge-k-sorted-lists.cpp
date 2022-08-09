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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        if(l1) temp->next=l1;
        if(l2) temp->next=l2;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        ListNode* head=lists[0];
        // cout<<node->val<<" ";
        for(int i=1;i<n;i++){
            head=merge(lists[i],head);
        }
        return head;
    }
};