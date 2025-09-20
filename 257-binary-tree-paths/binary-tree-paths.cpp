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
  void findPaths(TreeNode* root,vector<string>&result,string path){
    if(root==NULL)return;
    //Append curr Node to Path
    if(!path.empty())path+="->";
    path+=to_string(root->val);
    //Both left & right node becomes Null
    if(root->left==NULL && root->right==NULL)result.push_back(path);
    findPaths(root->left,result,path);
    findPaths(root->right,result,path);

  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        findPaths(root,result,"");
        return result;
    }
};