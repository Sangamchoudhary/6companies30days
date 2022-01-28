
Time --> O(N^2)
Space --> O(N^2)

class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int> &piles,int sum){
        if(i > j) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        
        int option1 = piles[i] + min(solve(i+2,j,piles,sum) , solve(i+1,j-1,piles,sum));
        
        int option2 = piles[j] + min(solve(i+1,j-1,piles,sum) , solve(i,j-2,piles,sum));
        
        int alice = max(option1,option2);
        
        return dp[i][j] = alice;
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0, j = n-1;
        
        memset(dp,-1,sizeof dp);
        
        int sum = accumulate(piles.begin(),piles.end(),0);
        
        int alice = solve(i,j,piles,sum);
        int bob = sum - alice;
        
        int res = alice > bob;
        return res;
    }
};