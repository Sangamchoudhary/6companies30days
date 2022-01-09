
Language --> C++

Time --> O(N)
Explanation --> because we are only traversing nodes once

let k = no of leaf nodes
Space --> O(N + 2*k)
Explanation --> Apart from nodes value, we store 2 INT_MIN for 1 leaf node 

class Solution
{
    public:
    void preOrder(Node* root,vector<int> &ans){
        if(!root){
            ans.push_back(INT_MIN);
            return;
        }
        ans.push_back(root->data);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    vector<int> serialize(Node *root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }
    
    Node* solve(vector<int> &A,int &n){
        if(A.size() == n or A[n] == INT_MIN){
            n++;
            return nullptr;
        }
        Node* node = new Node(A[n]);
        n++;
        node->left = solve(A,n);
        node->right = solve(A,n);
        return node;
    }
    
    Node* deSerialize(vector<int> &A){
       int v = 0;
       return solve(A,v);
    }

};