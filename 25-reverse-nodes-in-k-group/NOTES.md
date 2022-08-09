**1-RECURSIVE**
#### APPROACH
1) Check whether the Head is NULL or Not, if its NULL return NULL,
2) If Head is not NULL, then we need to check the length of Linked List starting from current Head.
3) If it is not a multiple of K(Less than K) , then there is no need to reverse it directly return head,
4) Else if its a multiple of K, then reverse the K elements starting from current Head,
5) Follow the same steps for the rest of the elements Recursively.

```
ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode *KSizeChecker = head;
        for(int i=0;i<k;i++)
        {
            if(KSizeChecker==NULL)
                return head;
            KSizeChecker = KSizeChecker->next;
        }
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k){
            // cout<<curr->val<<" ";
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
```

**Solution 2:(Iterative)**
#### APPROACH

1) Find out the length of linked list,"Len"
2) Find how many groups of size "K" are there to reverse--- "Len/K"
3) Len/K groups to reverse,
4) Find the new Linked List's Head(After reversal), we will make a dummyNode just before the head,
and at last for new Head we can directly return dummyNode->next,
5) The reversal of linked list is very easy ,
we just need to keep track of remaining Nodes and the new head for reversed linked list.

```
int length(ListNode *head)
    {
        ListNode *ptr = head;
        int cnt=0;
        while(ptr)
        {
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head)
            return NULL;
    
        int len = length(head);
        if(len<k)
            return head;
        
        int n = len/k;  //numberOfGroupsToReverse
        
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *start = dummyNode;

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
