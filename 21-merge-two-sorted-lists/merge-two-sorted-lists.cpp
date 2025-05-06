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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=NULL;
        ListNode* temp=dummyNode;

        while(t1!=NULL && t2!=NULL)
    {
        if(t1->val<=t2->val)
        {
             temp->next=t1;
             t1=t1->next;
             temp=temp->next;
        }

        else {
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
        }
    }

    while(t1!=NULL )
    {
        temp->next=t1;
        t1=t1->next;
        temp=temp->next;
    }

    while(t2!=NULL)
    {
        temp->next=t2;
        t2=t2->next;
        temp=temp->next;
    }
    return dummyNode->next;
    }
};