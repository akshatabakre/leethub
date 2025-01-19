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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        queue<TreeNode*> st;
        st.push(root);
        int flag = 0;
        while(!st.empty()){
            int size = st.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* n = st.front();
                st.pop();
                level.push_back(n->val);
                if(n->left!=NULL){
                    st.push(n->left);
                }
                if(n->right!=NULL){
                    st.push(n->right);
                }
            }
            if(flag==1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};