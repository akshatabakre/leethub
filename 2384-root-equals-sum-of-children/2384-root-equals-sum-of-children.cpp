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
    bool solve(TreeNode* root){
        if(!root || (!root->left && !root->right)){
            return true;
        }
        int sum = 0;
        if(root->left)  sum+=root->left->val;
        if(root->right) sum+=root->right->val;
        cout<<sum<<" "<<root->val<<endl;
        return (root->val==sum && (!root->right || solve(root->right)) && (!root->left || solve(root->left)));
    }
    bool checkTree(TreeNode* root) {
        if(!root)   return false;
        return solve(root);
    }
};