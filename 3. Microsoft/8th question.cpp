// 1st approach -- DFS
Time --> O(N)
Aux Space --> O(N)

class Solution {
public:
    
    Node* solve(Node* root,Node* parent){
        if(!root) return NULL;
        
        if(root->left and root->right){
            root->left->next = root->right;
            if(root->next){
                root->right->next = root->next->left;
            }
        }

        solve(root->left,root);
        solve(root->right,root);
                
        return root;
    }
    
    Node* connect(Node* root){
        return solve(root,NULL);
    }
};

// 2nd approach -- constant space
Time --> O(N)
Space --> O(1)

class Solution {
public:    
    Node* connect(Node* root){
        auto head = root;
        if(!root) return root;
        while(head->left){
            auto curr = head;
            while(curr){
                curr->left->next = curr->right;
                if(!curr->next) break;
                curr->right->next = curr->next->left;
                curr = curr->next;
            }
            head = head->left;
        }
        return root;              
    }
};

//3rd approach -- BFS
Time --> O(N)
Space --> O(N) , for queue

class Solution {
public:    
    Node* connect(Node* root){             
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            long long size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                if(size > 0) node->next = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return root;
    }
};