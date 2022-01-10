
The most clean code you will ever get

Language --> C++

Time --> O(N)

Space --> O(3N) , parent array + burned Nodes array + queue
Aux Space --> O(2N) , as 2 dfs are working

class Solution {
  public:
    bool check(Node* root,vector<int> bn){
        if(!root) return false;
        if(bn[root->data] == -1) return false;
        return true;
    }
  
    void pushTarget(Node* root,int target,queue<Node*> &q){
        if(!root) return;
        if(root->data == target){
            q.push(root);
            return;
        }
        pushTarget(root->left,target,q);
        pushTarget(root->right,target,q);
    }
    
    void assignParent(Node* child,Node* par,vector<Node*>&parent){
        if(!child) return;
        parent[child->data] = par;
    }
    
    void dfs(Node* root,vector<Node*> &parent){
        if(!root) return;
        assignParent(root->left,root,parent);
        assignParent(root->right,root,parent);
        dfs(root->left,parent);
        dfs(root->right,parent);
    }
  
    int minTime(Node* root, int target){
        vector<Node*> parent(100001);
        dfs(root,parent);
        
        queue<Node*> q;
        pushTarget(root,target,q);
        
        vector<int> burnedNode(100001);
        int t = -1;
        while(!q.empty()){
            int size = q.size();
            t++;
            while(size--){
                auto top = q.front();
                q.pop();
                burnedNode[top->data] = -1;
                
                if(check(top->left,burnedNode)) 
                    q.push(top->left);
                    
                if(check(top->right,burnedNode)) 
                    q.push(top->right);
                    
                if(check(parent[top->data],burnedNode))
                    q.push(parent[top->data]);
            }
        }
        
        return t;
    }
};