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
    int heightWithBalanceCheck(TreeNode* root,bool& b){
        if(!root)       return 0;
        int leftHeight = heightWithBalanceCheck(root->left,b);
        int rightHeight = heightWithBalanceCheck(root->right,b);
        if(abs(leftHeight-rightHeight)>1){
            b = false;
        }
        return 1 + max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool b = true;
        int height = heightWithBalanceCheck(root,b);
        return b;
    }
};