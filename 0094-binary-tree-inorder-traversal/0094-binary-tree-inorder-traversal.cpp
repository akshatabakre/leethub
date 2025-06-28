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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr){
            TreeNode* l = curr->left;//left's rightmost
            if(l){
                while(l->right && l->right!=curr){
                    l = l->right;
                }
                if(l->right==curr){
                    l->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }else{
                    l->right = curr;
                    curr = curr->left;
                }
            }else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};