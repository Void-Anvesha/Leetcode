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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftDummy=new ListNode(-1,NULL);
        ListNode* rightDummy=new ListNode(-1,NULL);
        ListNode* left=leftDummy;
        ListNode* right=rightDummy;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                left->next=temp;
                left=temp;
            }
            else{
            right->next=temp;
            right=temp;
            }
            temp=temp->next;
        }
        right->next=NULL;
        left->next=rightDummy->next;
        return leftDummy->next;
        
    }
};