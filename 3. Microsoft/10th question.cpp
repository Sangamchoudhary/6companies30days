

// 1st approach ----> Memorization
Time --> O(N)
Space --> O(N)

class Solution{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10001];
    int solve(int arr[],int n,int i,int ans){
        if(i>=n)
            return 0;
            
        if(dp[i] != -1)
            return dp[i];
            
        ans += arr[i] + max(solve(arr,n,i+2,ans),solve(arr,n,i+3,ans));
        
        return dp[i] = ans;
    }
    int FindMaxSum(int arr[], int n){
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        return max(solve(arr,n,0,ans),solve(arr,n,1,ans));
    }
};

// 2nd Approach ----> Tabulation
Time --> O(N)
Space --> O(N)
Aux Space --> O(N)
int FindMaxSum(int a[], int n){
        // Your code here
        if(n==1)
            return a[0];
        if(n==2)
            return max(a[0],a[1]);
        
        vector<int> dp(n);
        dp[0]=a[0], dp[1]=a[1], dp[2] = a[0]+a[2];
        
        for(int i=3;i<n;i++){
            dp[i] = a[i] + max(dp[i-2],dp[i-3]);
        }
        
        return max(dp[n-1],dp[n-2]);
}