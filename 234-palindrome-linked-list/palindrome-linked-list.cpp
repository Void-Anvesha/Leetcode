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
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;

        while(f->next!=NULL && f->next->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }

        ListNode* newHead=reverse(s->next);

        ListNode* first=head;
        ListNode* second=newHead;

        while(second!=NULL)
        {
            if(first->val != second->val)
            {
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverse(newHead);
        return true;

    }

    ListNode* reverse(ListNode* head)
    {

        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
       ListNode* newHead=reverse(head->next);
       ListNode* front=head->next;
       front->next=head;
       head->next=NULL;
       return newHead;

    }
};