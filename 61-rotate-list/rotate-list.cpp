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
 ListNode* findNthNode(ListNode* temp, int t)
 {
    int cnt=1;
    while(temp!=NULL)
    {
        if(cnt==t) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail=head;
        int len=1;

        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }

        if(len==k)return head;
         k=k%len;

         tail->next=head;

         ListNode* newLastNode=findNthNode(head,len-k);
         head=newLastNode->next;
         newLastNode->next=NULL;


         return head;


    }
};