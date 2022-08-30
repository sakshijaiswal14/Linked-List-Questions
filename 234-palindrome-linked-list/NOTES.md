ListNode* temp=head;
vector<int> num;
while(temp!=NULL){
num.push_back(temp->val);
temp=temp->next;
}
int i=0,j=num.size()-1;
while(i<=j){
if(num[i]==num[j]){
i++,j--;
}
else return false;
}
return true;
}
​
**2-EFFICIENT APPROACH**
1. find mid element
2. reverse half of ll with mid element
3. compare ll from starting and middle by movind pointers by each step
```
ListNode* reverse(ListNode* head){
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
bool isPalindrome(ListNode* head) {
ListNode* slow=head;
ListNode* fast=head;
while(fast!=NULL && fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
}