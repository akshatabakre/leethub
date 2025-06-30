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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushNodes(TreeNode* root){
        if(!root)   return;
        TreeNode* curr = root;
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        int x = top->val;
        st.pop();
        pushNodes(top->right);
        return x;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */