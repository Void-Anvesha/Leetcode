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

    void rightViewElements(TreeNode* root,int level,vector<int>& ans){
        if(root==NULL) return;
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        rightViewElements(root->right,level+1,ans);
        rightViewElements(root->left,level+1,ans);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightViewElements(root,0,ans);
        return ans;
    }
};