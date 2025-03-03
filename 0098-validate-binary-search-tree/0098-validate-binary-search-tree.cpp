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
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return true;
        }
        bool flag = true;
        if(root->left){
            TreeNode* curr = root->left;
            while(curr->right){
                curr = curr->right;
            }
            if(curr->val>=root->val){
                flag = false;
            }
        }
        if(root->right){
            TreeNode* curr = root->right;
            while(curr->left){
                curr = curr->left;
            }
            if(curr->val<=root->val){
                flag = false;
            }
        }
        return flag && isValidBST(root->left) && isValidBST(root->right);
    }
};