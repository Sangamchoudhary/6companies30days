Going from land to water -- hence more optimize

int x[] = {-1,0,1,0};    // direction matric ( from up then clockwise (up-left-down-right)  )
int y[] = {0,1,0,-1};
class Solution {
public:    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // step 1 : pushing all coordinates of land
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(grid[i][j] == 1)
                    q.push({i,j});
    
        // if matrix has no water then ans = -1 so return 
        if(q.size() == n*m)
            return -1;
        
        int dist = 0;
        
        // standard BFS
        while(q.size())
        {
            int size = q.size();
            dist++;
            while(size--)
            {
                auto [si , sj] = q.front(); q.pop();
                
                for(int i=0 ; i<4; i++)
                {
                    int newi = si + x[i];
                    int newj = sj + y[i];
                    if(newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj] == 0)
                        q.push({newi,newj}) , grid[newi][newj] = 1;
                }
            }  
        }
        return dist-1;
    }
};
Goind from water to land - passed 34/35 test cases

class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int> (n,0));
        int ans = 0;
        
        int zero = 0, one = 0;
        for(auto it : grid) for(auto i : it) if(i == 0) zero++; else one++;
        if(zero == n*n or one == n*n) return -1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    int d = 0;
                    bool flag = false;
                    while(q.size()){
                        int size = q.size();
                        d++;
                        
                        while(size--){
                            auto x = q.front().first;
                            auto y = q.front().second;
                            q.pop();
                            
                            if(x+1 < n){
                                if(grid[x+1][y] == 1) flag = true;
                                q.push({x+1,y});
                            }
                            if(x-1 >= 0){
                                if(grid[x-1][y] == 1) flag = true;
                                q.push({x-1,y});
                            }
                            if(y+1 < n){
                                if(grid[x][y+1] == 1) flag = true;
                                q.push({x,y+1});
                            }
                            if(y-1 >= 0){
                                if(grid[x][y-1] == 1) flag = true;
                                q.push({x,y-1});
                            }                            
                            
                        }
                        if(flag) break;
                    }
                    dist[i][j] = d;
                    ans = max(ans,dist[i][j]);
                }
            }
        }
        return ans;
    }
};