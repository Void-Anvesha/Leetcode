/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void inorder(TreeNode* root,vector<int>&ds){
    if(root==NULL)return;
    inorder(root->left,ds);
    ds.push_back(root->val);
    inorder(root->right,ds);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ds;
        inorder(root,ds);

        int i=0;
        int j=ds.size()-1;
        while(i<j){
            if((ds[i]+ds[j])==k)return true;
            else if((ds[i]+ds[j])>k)j--;
            else i++;
        }
        return false;
    }
};