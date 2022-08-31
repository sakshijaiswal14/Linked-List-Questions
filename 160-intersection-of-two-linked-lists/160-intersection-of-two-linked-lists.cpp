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
ListNode *getIntersectionNode(ListNode* h1, ListNode* h2)
{
    // Your Code Here
    unordered_set<ListNode*> s;
    while(h1!=NULL){
        s.insert(h1);
        h1=h1->next;
    }
    while(h2!=NULL){
        if(s.find(h2)!=s.end()){
           return h2;
        }
        h2=h2->next;
    }
    return NULL;
}
};