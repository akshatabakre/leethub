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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val==key){//root needs to be deleted
            if(root->right){
                TreeNode* conn = root->right;
                while(conn->left){
                    conn = conn->left;
                }
                conn->left = root->left;
                return root->right;
            }else{
                return root->left;
            }
        }
        TreeNode* curr = root;
        while(curr){
            if(curr->val > key){//go to left
                if(curr->left){
                    if(curr->left->val==key){//L to be deleted
                        TreeNode* target = curr->left;
                        if(target->right){
                            TreeNode* conn = target->right;
                            while(conn->left){
                                conn = conn->left;
                            }
                            conn->left = target->left;
                            curr->left = target->right;
                            return root;
                        }else{
                            curr->left = target->left;
                            return root;
                        }
                    }else{
                        curr = curr->left;
                    }
                }else{
                    return root;
                }
            }else{//right child to be deleted
                if(curr->right){
                    if(curr->right->val==key){
                        TreeNode* target = curr->right;
                        if(target->right){
                            TreeNode* conn = target->right;
                            while(conn->left){
                                conn = conn->left;
                            }
                            conn->left = target->left;
                            curr->right = target->right;
                            return root;
                        }else{
                            curr->right = target->left;
                            return root;
                        }
                    }else{
                        curr = curr->right;
                    }
                }else{
                    return root;
                }
            }
        }
        return root;
    }
};