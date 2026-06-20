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
    vector<string> ans;
    string helper(TreeNode* root, string path){
        
        if(root==NULL)  return "";
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return "";
        }
        if(root->left != NULL || root->right != NULL)
            path += "->";
        string left = helper(root->left, path);
        string right = helper(root->right, path);
        
        return path;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root, "");
        return ans;
    }
};