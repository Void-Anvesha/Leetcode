/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        int curr=root->val;

        if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        //If there is a root & in 1 side p is there & the other side q 
        //Then the particular root is LCA
        return root;
    }
};