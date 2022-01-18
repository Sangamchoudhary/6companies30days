
Time --> 

class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int> &arr,int n){
        
        if(i > j) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = arr[i] + min(solve(i+2,j,arr,n),solve(i+1,j-1,arr,n));
        int op2 = arr[j] + min(solve(i+1,j-1,arr,n),solve(i,j-2,arr,n));
        
        return dp[i][j] = max(op1,op2);
    }
    
    int maxCoins(vector<int>&A,int n){
        memset(dp,-1,sizeof dp);
	    return solve(0,n-1,A,n);
    }
};