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
    int camera = 0;
    
    int helper(TreeNode* root, int& curr){
        if(root == NULL){
            return 1;
        }
        int left = helper(root->left, curr);
        int right = helper(root->right, curr);
        if(left==-1 || right==-1)
        {
            camera += 1;
            curr = 0;
        }
        else if(left == 0 || right == 0){
            curr = 1;
        }
        else
            curr = -1;
        return curr;
    }
    int minCameraCover(TreeNode* root) {
        int curr = INT_MIN;
        int val = helper(root, curr);
        if(val == -1)
            camera = camera+1;
        return camera;
    }
};