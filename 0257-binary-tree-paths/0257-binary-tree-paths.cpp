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
    bool isLeaf(TreeNode* root){
        return (!root->left && !root->right);
    }
    void solve(TreeNode* node,vector<int>& v,vector<string>& ans){
        if(!node){
            return;
        }
        v.push_back(node->val);
        if(isLeaf(node)){
            //convert v to string
            string str = "";
            for(int i=0;i<v.size();i++){
                // if(v[i]<0){
                //     str+='-';
                // }
                // int n = abs(v[i]);
                str+=to_string(v[i]);
                if(i!=v.size()-1){
                    str += "->";
                }
            }
            ans.push_back(str);
            v.pop_back();
            return;
        }
        solve(node->left,v,ans);
        solve(node->right,v,ans);
        v.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> v;
        solve(root,v,ans);
        return ans;
    }
};