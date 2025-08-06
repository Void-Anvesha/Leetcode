class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (node != nullptr || !st.empty()) {
            // Go left as far as possible
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            // Node is null here, pop from stack
            node = st.top();
            st.pop();
            ans.push_back(node->val);

            // Visit right subtree
            node = node->right;
        }

        return ans;
    }
};
