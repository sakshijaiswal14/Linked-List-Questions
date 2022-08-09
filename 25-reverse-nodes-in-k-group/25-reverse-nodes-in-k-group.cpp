class Solution {
public:
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
};