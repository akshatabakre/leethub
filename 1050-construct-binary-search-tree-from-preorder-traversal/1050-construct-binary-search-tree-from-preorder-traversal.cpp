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
    TreeNode* f(vector<int>& pre,int& ind,int upper){
        if(ind==pre.size() || pre[ind]>upper){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[ind]);
        ind++;
        root->left = f(pre,ind,root->val);
        root->right = f(pre,ind,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return f(preorder,ind,1e9);
    }
};