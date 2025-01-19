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
    int maxpath(TreeNode* n,int& maxi){
        if(n==NULL){
            return 0;
        }
        int left = maxpath(n->left,maxi);
        int right = maxpath(n->right,maxi);
       if(left<=0 && right<=0){
            maxi = max(maxi,n->val);
            return n->val;
       }else if(left<=0){
        maxi = max(maxi,n->val+right);
        return n->val+right;
       }else if(right<=0){
        maxi = max(maxi,n->val+left);
        return n->val+left;
       }
        maxi = max(maxi,left+right+n->val);
        return n->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        maxpath(root,maxi);
        return maxi;
    }
};