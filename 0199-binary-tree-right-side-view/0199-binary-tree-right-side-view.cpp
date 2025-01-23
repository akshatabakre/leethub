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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,int> m;//level->nodedata
        vector<int> ans;
        if(!root)   return ans;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            TreeNode* n = p.first;
            int l = p.second;
            m[l] = n->val;
            if(n->left){
                q.push({n->left,l+1});
            }
            if(n->right){
                q.push({n->right,l+1});
            }
            q.pop();
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};