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
    int leftH(TreeNode* root){
        int h = 1;
        TreeNode* curr = root;
        while(curr->left){
            curr = curr->left;
            h++;
        }
        return h;
    }
    int rightH(TreeNode* root){
        int h = 0;
        TreeNode* curr = root;
        while(curr->right){
            curr = curr->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int LH = leftH(root);
        int RH = rightH(root);
        if(LH==RH){
            return (1<<LH)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};