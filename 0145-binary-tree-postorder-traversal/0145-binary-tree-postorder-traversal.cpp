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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre,in,post;
        stack<pair<TreeNode*,int>> st;
        if(!root)   return post;
        st.push({root,1});
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int  status = st.top().second;
            st.pop();
            if(status==1){
                pre.push_back(node->val);
                st.push({node,2});
                if(node->left)      st.push({node->left,1});
            }else if(status==2){
                in.push_back(node->val);
                st.push({node,3});
                if(node->right)     st.push({node->right,1});
            }else if(status==3){
                post.push_back(node->val);
            }
        }
        return post;
    }
};