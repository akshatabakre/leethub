/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        vector<int> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left){
                    parent[n->left] = n;
                    q.push(n->left);
                }
                if(n->right){
                    parent[n->right] = n;
                    q.push(n->right);
                }
            }
        }
        map<TreeNode*,bool> vis;
        vis[target] = true;
        q.push(target);
        int l = 0;
        while(!q.empty()){
            int size = q.size();
            if(l++ == k)    break;
            for(int i=0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left && !vis[n->left]){
                    vis[n->left] = true;
                    q.push(n->left);
                }
                if(n->right && !vis[n->right]){
                    vis[n->right] = true;
                    q.push(n->right);
                }
                if(parent[n] && !vis[parent[n]]){
                    vis[parent[n]] = true;
                    q.push(parent[n]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};