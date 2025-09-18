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
private:
TreeNode* prev;
TreeNode* last;
TreeNode* first;
TreeNode* middle;
public:
   void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);

    if(prev!=NULL && (prev->val>root->val)){
        //If it is the 1st violation,mark 2 nodes as first & middle
        if(first==NULL){
            first=prev;
            middle=root;
        }
        //If this is the 2nd violation
        else {
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
   }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val ,last->val);
        else if(first && middle)swap(first->val,middle->val);


    }
};