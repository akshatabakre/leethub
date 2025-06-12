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
    void traverse(TreeNode* root,int vert,int level,map<int,
    map<int,multiset<int>>>& mp,int& mini,int& maxi){
        if(!root)   return;
        mp[vert][level].insert(root->val);
        mini = min(vert,mini);
        maxi = max(vert,maxi);
        traverse(root->left,vert-1,level+1,mp,mini,maxi);
        traverse(root->right,vert+1,level+1,mp,mini,maxi);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        if(!root->left && !root->right){
            ans.push_back({root->val});
            return ans;
        }
        map<int,map<int,multiset<int>>> mp;
        int mini = 1e9, maxi = -1e9;
        traverse(root,0,0,mp,mini,maxi);
        ans.resize(maxi-mini+1);
        for(auto it1:mp){
            for(auto it2:it1.second){
                for(int i:it2.second){
                    ans[it1.first-mini].push_back(i);
                }
            }
        }
        return ans;
    }
};