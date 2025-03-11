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

class BSTIterator{
private:
stack<TreeNode*> s;
bool reverse;
public:
BSTIterator(TreeNode* root,bool reverse){
    this->reverse = reverse;
    pushnodes(root);
}
void pushnodes(TreeNode* root){
    while(root){
        s.push(root);
        root = (reverse)? root->right : root->left;
    }
}
bool hasnext(){
    return !s.empty();
}
int next(){
    TreeNode* n = s.top();
    s.pop();
    if(reverse){
        pushnodes(n->left);
    }else{
        pushnodes(n->right);
    }
    return n->val;
}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator n(root,0);
        BSTIterator b(root,1);
        int i = n.next(), j = b.next();
        while(i<j){
            if(i+j==k)  return true;
            if(i+j<k){
                i = n.next();
            }else{
                j = b.next();
            }
        }
        return false;
    }
};