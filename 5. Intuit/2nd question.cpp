
Let size of word = K
Time --> O(m * n * (4^K))
Space --> O((m*n) + K)

class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i < 0 or j < 0 or i >=m or j >= n)
            return false;
        return true;
    }

    bool solve(int i,int j,string str,vector<vector<char>>& board, string &word,vector<vector<bool>> &vis,int m,int n){
        
        if(!isValid(i,j,m,n) or vis[i][j] or str.size() > word.size()) 
            return false;
        else if(str.size() >= 1 and str.back() != word[str.size()-1]){
            return false;
        }
        else if(str.size() == word.size()){
            if(str == word) return true;
            else return false;
        }
        
        vis[i][j] = true;
        bool op1 = solve(i-1,j,str + board[i][j],board,word,vis,m,n);
        bool op2 = solve(i+1,j,str + board[i][j],board,word,vis,m,n);
        bool op3 = solve(i,j-1,str + board[i][j],board,word,vis,m,n);
        bool op4 = solve(i,j+1,str + board[i][j],board,word,vis,m,n);
        vis[i][j] = false;
        
        bool final = (op1 or op2 or op3 or op4);
        
        return final;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j] == word[0] and solve(i,j,"",board,word,vis,m,n)) 
                return true;
                
        return false;                
    }
};