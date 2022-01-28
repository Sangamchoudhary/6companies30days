
Time --> O(N)
Aux Space --> O(N)

class Solution {
  public:
    int solve(Node* root){
        if(!root) return 0;
        
        int ls = solve(root->left);
        int rs = solve(root->right);
        
        root->data += + ls + rs;
        
        return root->data;
    }
  
    void toSumTree(Node *root){
        solve(root);
    }
};