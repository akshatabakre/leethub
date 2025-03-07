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
    bool preorder(TreeNode* n, long long l, long long r){
        if(!n){
            return true;
        }
        return (n->val>l && n->val<r) && preorder(n->left,l,n->val) && preorder(n->right,n->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return preorder(root,-1e10,1e10);
    }
};