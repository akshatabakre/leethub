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
    map<int,int> mp;
    int f1(TreeNode* node,int level){
        queue<TreeNode*> q;
        q.push(node);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            if(cnt==level){
                return size;
            }
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            cnt++;
        }
        return 0;
    }
    void func(TreeNode* root,int level){
        if(root==NULL){
            return;
        }
        mp[level]++;
        func(root->left,level+1);
        func(root->right,level+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        func(root,0);
        int maxi = 0;
        for(auto it:mp){
            maxi = max(it.first,maxi);
        }
        int num = mp[maxi];
        TreeNode* ans = root;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int size = q.size();
            for(int j=0;j<size;j++){
                auto it = q.front();
                q.pop();
                if(f1(it,maxi-i)==num){
                    ans = it;
                }
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            i++;
        }
        return ans;
    }
};