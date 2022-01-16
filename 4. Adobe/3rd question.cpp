
Time --> O(N * K)
Space --> O(N * k)

class Solution{
  public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    long long int solve(int N,int k,int cnt){
        if(N == 0) return 1;
        
        if(dp[N][cnt] != -1) return dp[N][cnt];
        
        if(cnt < k) return dp[N][cnt] = ((21*solve(N-1,k,0)) + (5*solve(N-1,k,cnt+1)))%mod;
        
        if(cnt == k)  return dp[N][cnt] = (21*solve(N-1,k,0))%mod;
    }
  
    int kvowelwords(int N, int K) {
        memset(dp,-1,sizeof dp);
        return solve(N,K,0)%mod;
    }
};