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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        //Move fast for N steps
        //So that we reach before (N-1)th index
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
      //delete head
        if(fast == NULL){
          ListNode* deleteNode = head;
          head = head->next;
          delete(deleteNode);
          return head;
        }
        // Now, move both fast & slow pointer
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    //Now the slow->next is to be deleted
    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);

    return head;
    }
};