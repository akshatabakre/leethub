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
    void solve(TreeNode* root,TreeNode* &prev){
        if(!root)   return;
        solve(root->right,prev);
        solve(root->left,prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return;
    }
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right))   return;
        // TreeNode* curr = root;
        // while(curr){
        //     if(curr->left==NULL){
        //         curr = curr->right;
        //     }else{
        //         TreeNode* ptr = curr->left;
        //         while(ptr->right!=NULL){
        //             ptr = ptr->right;
        //         }
        //         ptr->right = curr->right;
        //         TreeNode* lft = curr->left;
        //         curr->left = NULL;
        //         curr->right = lft;
        //         curr = curr->right;
        //     }
        // }
        // return;

        //recursive
        TreeNode* prev = NULL;
        solve(root,prev);
        return;
    }
};