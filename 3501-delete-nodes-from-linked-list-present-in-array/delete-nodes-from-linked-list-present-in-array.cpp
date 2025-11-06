
 /* Definition for singly-linked list.
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>mp(nums.begin(),nums.end());
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            int val = temp->val;

            // Check if the value is in nums and needs deletion
            if (mp.find(val)!=mp.end()) {
                // Node needs to be removed
                if (prev==NULL) {
                    head = head->next;
                } else {
                    prev->next = temp->next;
                    
                }
            } else {
                // Move both pointers forward if no deletion
                prev = temp;
            }
            temp=temp->next;
        }

        return head;
    }
};
