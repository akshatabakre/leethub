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
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL){
                ans+='#';
                ans+=',';
            }else{
                ans+=to_string(node->val);
                ans+=',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left = NULL;
            }else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right = NULL;
            }else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));