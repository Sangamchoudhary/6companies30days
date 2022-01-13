
Time --> O(m*n)
Space --> O(1)
Aux Space --> O(m*n)

class Solution
{
    public:
    
    void solve(int i,int j,vector<vector<int>>&grid,int &count,int &ans){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        count++;
        solve(i-1,j,grid,count,ans);
        solve(i+1,j,grid,count,ans);
        solve(i,j-1,grid,count,ans);
        solve(i,j+1,grid,count,ans);
        solve(i-1,j-1,grid,count,ans);
        solve(i+1,j+1,grid,count,ans);
        solve(i-1,j+1,grid,count,ans);
        solve(i+1,j-1,grid,count,ans);
    }
    
    int findMaxArea(vector<vector<int>>&grid){
        int ans = 0;
        int m = grid.size() , n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 0;
                if(grid[i][j] == 1)
                    solve(i,j,grid,count,ans);
                ans = max(ans,count);
            }
        }  
        return ans;
    }
};