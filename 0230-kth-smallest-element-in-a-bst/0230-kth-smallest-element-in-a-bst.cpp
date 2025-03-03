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
    int kthSmallest(TreeNode* root, int k) {
        if(!root->left && !root->right){
            return root->val;
        }
        stack<TreeNode*> s;
        // s.push(root);
        TreeNode* curr = root;
        int count = 0;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            count++;
            if(count==k){
                return curr->val;
            }
            s.pop();
            curr = curr->right;
        }
        return 0;
    }
};