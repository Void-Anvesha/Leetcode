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
    int maxLevelSum(TreeNode* root) {
       int maxSum = INT_MIN;
       int resLevel = 0;

       queue<TreeNode*> q;
       q.push(root);
       int currLevel=1;

       while(!q.empty()){

        int n = q.size();
        int sum=0;

        //Travsere all the nodes of the curr level
        while(n--){
            TreeNode* temp = q.front();
            q.pop();

            sum+=temp->val;

            if(temp->left)q.push(temp->left);
            
            if(temp->right)q.push(temp->right);
          

        }
        if(sum > maxSum){
            maxSum = sum;
            resLevel = currLevel;
        }
        currLevel++;
    
       }   
       return resLevel;
    }
};