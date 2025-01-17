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
    // void inord(TreeNode* n,vector<int>& ans){
    //     if(n==NULL)     return;
    //     inord(n->left,ans);
    //     ans.push_back(n->val);
    //     inord(n->right,ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inord(root,ans);
        // return ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*> s;
        TreeNode* n = root;
        while(true){
            if(n!=NULL){
                s.push(n);
                n = n->left;
            }else{//null node encountered
                if(s.empty())   break;
                n = s.top();//re-initializing n to top of stack, as cant traverse the tree more (as the NULL node is encountered), basically backtracking
                s.pop();
                ans.push_back(n->val);
                n = n->right;
            }
        }
        return ans;
    }
};