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

class BST_Iterator{
    stack<TreeNode*> st;
    bool flag;//successor if true
    public:
    BST_Iterator(TreeNode* root,bool flag){
        this->flag = flag;
        pushNodes(root);
    }
    void pushNodes(TreeNode* root){
        if(!root)   return;
        TreeNode* curr = root;
        while(curr){
            st.push(curr);
            if(flag){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    bool empty(){
        return st.empty();
    }
    int move(){
        TreeNode* top = st.top();
        int x = top->val;
        st.pop();
        if(flag){
            pushNodes(top->right);
        }else{
            pushNodes(top->left);
        }
        return x;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BST_Iterator next(root,true), prev(root,false);
        int x = next.move(), y = prev.move();
        while(x<y && !next.empty() && !prev.empty()){
            if(x + y == k){
                return true;
            }
            if(x+y > k){
                cout<<"prev"<<endl;
                y = prev.move();
            }else{
                cout<<"next"<<endl;
                x = next.move();
            }
        }
        return false;
    }
};