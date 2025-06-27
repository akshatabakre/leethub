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
    bool isLeaf(TreeNode* root){    return (!root->left && !root->right);}
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*,ll>> q;//node,index
        q.push({root,0LL});
        ll maxWidth = 0;
        while(!q.empty()){
            int levsize = q.size();
            ll leftIndex = 1e9, rightIndex = -1e9;
            ll minind = q.front().second;//WHY MININD - draw skewed right tree and give indices for worst case
            for(int i=0;i<levsize;i++){
                TreeNode* node = q.front().first;
                ll currInd = q.front().second-minind;
                q.pop();
                leftIndex = min(currInd,leftIndex);
                rightIndex = max(currInd,rightIndex);
                if(node->left){
                    ll leftInd = 2*currInd;
                    q.push({node->left,leftInd});
                }
                if(node->right){
                    ll rightInd = 2*currInd + 1;
                    q.push({node->right,rightInd});
                }
            }
            maxWidth = max(rightIndex - leftIndex + 1,maxWidth);
        }
        return (int)maxWidth;
    }
};