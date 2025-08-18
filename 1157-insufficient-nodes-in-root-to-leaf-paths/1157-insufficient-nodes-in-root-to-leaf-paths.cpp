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
    bool isLeaf(TreeNode*root){
        return (!root->left && !root->right);
    }
    bool mark(TreeNode* root,int sum,map<TreeNode*,bool>& suff,int& limit){
        if(isLeaf(root)){
            if(sum+root->val>=limit){
                suff[root] = true;
                return true;
            }else{
                suff[root] = false;
                return false;
            }
        }
        bool left = false,right = false;
        if(root->left)
         left = mark(root->left,sum+root->val,suff,limit);
        if(root->right)
         right = mark(root->right,sum+root->val,suff,limit);
        suff[root] = (left||right);
        return suff[root];
    }
    void clear(TreeNode* root,map<TreeNode*,bool>&suff){
        if(isLeaf(root)){
            return;
        }
        if(root->left){
            if(suff[root->left]==false)
                root->left = NULL;
            else
                clear(root->left,suff);
        }
        if(root->right){
            if(suff[root->right]==false)
                root->right = NULL;
            else
                clear(root->right,suff);
        }
        return;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        map<TreeNode*,bool> suff;
        mark(root,0,suff,limit);
        if(suff[root]==false){
            return NULL;
        }
        clear(root,suff);
        return root;
    }
};