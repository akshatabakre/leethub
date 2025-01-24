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
        if(!root)   return 0;
        queue<pair<TreeNode*,int>> q;//node,index
        q.push({root,1});
        ll ans = 1;
        while(!q.empty()){
            auto p = q.front();
            ll size = q.size();
            ll minin = p.second;
            ll left, right = 0;
            for(int i=0;i<size;i++){
                ll currind = q.front().second - minin;
                TreeNode* n = q.front().first;
                q.pop();
                if(i==0)    left = currind;
                if(i==size-1)   right = currind;
                if(n->left){
                    q.push({n->left,2*currind+1});
                }
                if(n->right){
                    q.push({n->right,2*currind+2});
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};