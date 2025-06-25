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
    void solve(TreeNode* root,int v,int l,map<int,map<int,multiset<int>>>& m){
        if(!root){
            return;
        }
        m[v][l].insert(root->val);
        solve(root->left,v-1,l+1,m);
        solve(root->right,v+1,l+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        solve(root,0,0,m);
        vector<vector<int>> ans;
        for(auto v:m){
            int vert = v.first;
            auto mp = v.second;
            vector<int> vec;
            for(auto l:mp){
                int lev = l.first;
                auto ms = l.second;
                
                for(int it:ms){
                    vec.push_back(it);
                }
            }
                ans.push_back(vec);
        }
            return ans;
    }
};