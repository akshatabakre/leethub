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
    bool check(TreeNode* p, TreeNode* q){
        if(!p || !q){
            return (p==q);
        }
        return (p->val== q->val && check(p->right,q->left) && check(p->left,q->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        if(!root->right && !root->left)     return true;
        return check(root->left,root->right);
    }
};