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
    bool rton(TreeNode* n,int p,vector<TreeNode*>& v){
        if(!n)  return false;
        v.push_back(n);
        if(n->val == p){
            return true;
        }
        if(!rton(n->left,p,v) && !rton(n->right,p,v)){
            v.pop_back();
            return false;
        }
        return true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        if(!root)   return NULL;
        rton(root,p->val,v1);
        rton(root,q->val,v2);
        // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        int i=0;
        while(i<min(v1.size(),v2.size())){
            if(v1[i]->val == v2[i]->val){
                i++;
            }else{
                break;
            }
        }
        return v1[i-1];
    }
};