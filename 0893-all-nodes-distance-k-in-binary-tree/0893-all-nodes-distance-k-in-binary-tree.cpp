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
        map<TreeNode*,bool> vis;
        map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        q.push(target);
        vis[target] = true;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(!q.empty()){
                int s = q.size();
                for(int i=0;i<s;i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr->left && !vis[curr->left]){
                        q.push(curr->left);
                        vis[curr->left] = true;
                    }
                    if(curr->right && !vis[curr->right]){
                        q.push(curr->right);
                        vis[curr->right] = true;
                    }
                    if(parent[curr] && !vis[parent[curr]]){
                        q.push(parent[curr]);
                        vis[parent[curr]] = true;
                    }
                }
            }else{
                break;
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};