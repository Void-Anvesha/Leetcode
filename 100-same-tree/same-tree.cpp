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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Base case
        //p: Root of 1st Tree
        //q:Root og 2nd tree
        if(p==NULL || q==NULL) return p==q;

        bool isLeftSame=isSameTree(p->left,q->left);
        bool isRightSame=isSameTree(p->right,q->right);

        return isLeftSame && isRightSame && ( p->val==q->val);

    }
};