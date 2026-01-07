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
vector<int> sums;
int mod = 1e9 + 7;
    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int s = root->val+sum(root->left) +sum(root->right);
        sums.push_back(s);
        return s;
    }
    int maxProduct(TreeNode* root) {
        #define int long long
        int total = sum(root);
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        for(int s:sums){
            ans = max(s*(total-s),ans);
        }
        return ans%mod;
        #undef int
    }
};