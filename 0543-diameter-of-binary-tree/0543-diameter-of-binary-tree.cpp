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
    int height(TreeNode* n,int& maxi){
        if(!n)   return 0;
        int l = height(n->left,maxi);
        int r = height(n->right,maxi);
        maxi  = max(l+r,maxi);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root,dia);
        return dia;
    }
};