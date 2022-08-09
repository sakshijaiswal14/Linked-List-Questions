if(len<k)
return head;
int n = len/k;  //numberOfGroupsToReverse
ListNode *dummyNode = new ListNode(-1);
dummyNode->next = head;
ListNode *start = dummyNode;
​
ListNode *pre,*remaining,*next;
for(int i=0;i<n;i++)
{
pre = NULL;
remaining = head;
for(int j=0;j<k;j++)
{
next = head->next;
head->next = pre;
pre=head;
head=next;
}
start->next = pre;
remaining->next = head;
start = remaining;
}
return dummyNode->next;
}
```
​