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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;

        int maxWidth=0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(q.size()>0){
            unsigned long long s_idx = q.front().second;
            unsigned long long e_idx = q.back().second;
            maxWidth = max(maxWidth, (int)(e_idx - s_idx + 1));
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                if(q.front().first->left)
                    q.push({q.front().first->left, 2*q.front().second + 1});
                if(q.front().first->right)
                    q.push({q.front().first->right, 2*q.front().second + 2});
                q.pop();
            }
        }
        return maxWidth;
    }
};