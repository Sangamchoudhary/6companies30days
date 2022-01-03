
Language --> c++

Time --> O(N)
Space --> O(N) for dp
Aux Space --> O(N)

class Solution {
	public:
	
    int dp[1000001];
    int mod = 1e9 + 7;
    int solve(string &s,int n,int i){
        
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        
        //taking digits
        int op1 = s[i] - '0';
        int op2 = 0;
        if(i < n-1) 
            op2 = (op1 * 10) + (s[i+1] - '0');
        
        //operations
        if(op1 > 0) 
            ans += solve(s,n,i+1) % mod;
        if(op1 > 0 and op2 > 0 and op2 < 27) 
            ans += solve(s,n,i+2) % mod;
        
        return dp[i] = ans;
    }
    
    int CountWays(string s) {
        memset(dp,-1,sizeof dp);
        int ans = solve(s,s.length(),0);
        return ans;
    }
};