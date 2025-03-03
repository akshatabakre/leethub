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
        //if root is key
        if(root->val==key){
            TreeNode* n = root->right;
            if(n){
                while(n->left){
                    n = n->left;
                }
                n->left = root->left;
                return root->right;
            }else{
                n = root->left;
                return n;
            }
            return NULL;
        }
        TreeNode* curr = root;
        TreeNode* prev = root;
        while(curr){
            if(curr->val==key){
                //delete this node
                TreeNode* n = curr->right;
                if(n){
                    if(prev->right==curr)
                        prev->right = curr->right;
                    else
                        prev->left = curr->right;
                    while(n->left){
                        n = n->left;
                    }
                    n->left = curr->left;
                }else{
                    if(prev->right==curr)
                        prev->right = curr->left;
                    else
                        prev->left = curr->left;
                }
                break;
            }else if(curr->val<key){
                prev = curr;
                curr = curr->right;
            }else{
                prev = curr;
                curr = curr->left;
            }
        }
        return root;
    }
};