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
void findPaths(TreeNode* root,vector<int>&path,vector<vector<int>>&paths,int currSum,int targetSum){
    if (root==NULL)return;
    currSum+=root->val;
    path.push_back(root->val);
    //If leaf node & currSum==target
    if(root->left==NULL && root->right==NULL){
        if(currSum==targetSum)paths.push_back(path);
    }
   
   else{
    findPaths(root->left,path,paths,currSum,targetSum);
    findPaths(root->right,path,paths,currSum,targetSum);
   }
   //Backtrack & remove nodes
   path.pop_back();

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>path;
        findPaths(root,path,paths,0,targetSum);
        return paths;
    }
};