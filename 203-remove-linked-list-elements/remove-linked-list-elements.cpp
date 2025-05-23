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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* temp=new ListNode(-1,NULL);
        temp->next=head;
        ListNode* prev=temp;
        while(head!=NULL)
        {
            if(head->val==val){
              prev->next=head->next;
            }
            else{
            prev=head;}
            
            head=head->next;
           
        }
        return temp->next;
        
    }
};