
Language --> C++

Let m -> no of rows and n -> no of coloumn
Time --> O(M * N) 

Space --> O(N) , for queue
Aux space -> O(1)

class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<vector<int>>&grid){
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1)
                return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        int m = grid.size() , n = grid[0].size();
        
        if(m == 1 and n == 1){
            if(grid[0][0] == 2 or grid[0][0] == 0) return 0;
            else return -1;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int t = -1;
        while(!q.empty()){
            int size = q.size();
            t++;
            while(size--){
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();
                if(isValid(x-1,y,m,n,grid)){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(isValid(x+1,y,m,n,grid)){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(isValid(x,y-1,m,n,grid)){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                if(isValid(x,y+1,m,n,grid)){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
            }
        }
        
        for(auto it:grid){
            for(auto i:it){
                if(i == 1) return -1;
            }
        }
        
        return t == -1 ? 0 : t;
    }
};