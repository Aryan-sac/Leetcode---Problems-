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
    int ans=0;
public:
    int ht(TreeNode* root){
        if(root==NULL) return 0;

        int leftht = ht(root->left);
        int rightht = ht(root->right);

        ans = max(ans, (leftht + rightht));
        return max(leftht , rightht)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ht(root);
        return ans;
    }
};