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
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left){
            st.push(root->left);
            root = root->left;
        };
    }
    
    int next() {
        TreeNode* curr = st.top();
        int val = curr->val;
        st.pop();
        if(curr->right){
            curr = curr->right;
            st.push(curr);
            while(curr->left){
                st.push(curr->left);
                curr = curr->left;
            };
        }
        return val;
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