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
    TreeNode* construct(vector<int>& pre,vector<int>& in,map<int,int>& inmap,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie){
            return NULL;
        }
        int rootVal = pre[ps];
        int rootInd = inmap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        int leftSubSize = rootInd-is;
        root->left = construct(pre,in,inmap,ps+1,ps+leftSubSize,is,rootInd-1);
        root->right = construct(pre,in,inmap,ps+leftSubSize+1,pe,rootInd+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            inmap[inorder[i]] = i;
        }
        return construct(preorder,inorder,inmap,0,n-1,0,n-1);
    }
};