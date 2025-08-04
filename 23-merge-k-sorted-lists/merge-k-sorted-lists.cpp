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
   class Compare{
    public: 
    bool operator()(ListNode* a ,ListNode* b)
    {  //logically a<=b
    //But heap ke case me it works opposite
        return a->val > b->val;
    }
   
   };  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
       int K=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,Compare>p;
    // Push the head of each list into the priority queue
        for(auto& it :lists)
        {
           if(it!=NULL) p.push(it);
        }

        ListNode* root=new ListNode(0);
        ListNode* tail=root;
        ListNode* temp;
        while(!p.empty())
        {
            temp=p.top();
            p.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next) p.push(temp->next);

        }
        return root->next;




    }
};