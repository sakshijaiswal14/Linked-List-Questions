**1-BRUTE FORCE**
*SAVE THE ELEMENTS IN REVERSE ORDER AND MAKE NEW LINKED LIST*
**TC-O(N)  SC-O(N)**
```
ListNode* reverseList(ListNode* head) {
if(head==NULL) return head;
vector<int> rev;
ListNode* temp= head;
while(temp!=NULL){
rev.push_back(temp->val);
temp=temp->next;
}
int n=rev.size();
ListNode* root=new ListNode(rev[n-1]);
ListNode* prev=root;
root->next=NULL;
for(int i=n-2;i>=0;i--){
ListNode* node=new ListNode(rev[i]);
root->next=node;
root=root->next;
}
return prev;
}
```
​
**2-EFFICIENT APPROACH**
**TC-O(N)  SC-O(1)**
HINT-THINK OF USING 3 POINTERS
curr,next,prev
​
```
ListNode* reverseList(ListNode* head) {
if(head==NULL) return head;
ListNode* curr=head;
ListNode* next=NULL;
ListNode* prev=NULL;
while(curr!=NULL){
next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
return prev;
}
```
​
​
​