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
//Find the rightMost el of the left subtree of the root node to be deleted
   TreeNode* findLastRight(TreeNode* root){
      if(root->right==NULL)return root;
      return findLastRight(root->right);
   }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;

        //Find the rightChild
        TreeNode* rightChild=root->right;
        //Find lastRight of left Subtree
        TreeNode* lastRight=findLastRight(root->left);
        //Point lastRight's right to rightChild
        lastRight->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key)return helper(root);
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val<key){
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
        }
        return dummy;
    }
};