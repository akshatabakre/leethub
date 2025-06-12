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
 #define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll maxw = 0;
        if(!root)   return maxw;

        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        while(!q.empty()){
            ll s = q.size();
            ll startind = q.front().second;//have to substract this from every 
            ll left = 0, right = 0;
            for(ll i=0;i<s;i++){
                auto node = q.front().first;
                ll currind = q.front().second - startind;
                q.pop();
                if(i==0)    left = currind;
                if(i==s-1)  right = currind;
                if(node->left)  q.push({node->left,2*currind + 1});
                if(node->right)  q.push({node->right,2*currind + 2});
            }
            maxw = max(right-left + 1, maxw);
        }
        return maxw;
    }
};