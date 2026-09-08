/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count(Node* root){
        if(root == NULL)
            return 0;
        
        return count(root->left)+count(root->right)+1;
    }
    bool check(Node* root, int n, int idx){
        if(!root)   
            return true;
        
        if(idx >= n)
            return false;
        
        return check(root->left, n, idx*2+1) && check(root->right, n, idx*2+2);
    }
    bool ValCheck(Node* root, int Pval){
        if(root == NULL)
            return true;
        if(root->data > Pval)
            return false;
        
        return ValCheck(root->left, root->data) && ValCheck(root->right, root->data);
        
    }
    
    bool isHeap(Node* tree) {
        // code here
        // count the nodes
        int n = count(tree);
        
        return check(tree, n, 0) && ValCheck(tree, INT_MAX);
    }
};