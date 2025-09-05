/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode==NULL) s.append("#,");
            else s.append(to_string(currNode->val)+',');
            if(currNode!=NULL)
            {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
//stringstream object. It is used to treat the input string data as a stream, allowing us to easily extract parts (tokens) of the string separated by commas
        stringstream s(data);
//str is a string variable that temporarily holds each token extracted from the stream.
        string str;
//getline(ss, str, ',') reads from the stream s until it encounters a comma, and stores the extracted token in str.
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
          //Left subtree
            getline(s,str,',');
            if(str=="#")
            {
                curr->left=NULL;

            }
            else{
                TreeNode* leftNode=new TreeNode(stoi(str));
                curr->left=leftNode;
                q.push(leftNode);
            }
           //Right subtree
           //encounters the next value 
           getline(s,str,',');
            if(str=="#")
            {
                curr->right=NULL;

            }
            else{
                TreeNode* rightNode=new TreeNode(stoi(str));
                curr->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
         

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));