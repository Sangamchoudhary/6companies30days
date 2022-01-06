
Language --> C++

Time --> O(N)
Space --> O(N) , for dp array

long long dp[46] = {0};
long long countWays(int n) {
    if(n <= 1) return n; 
    else if(n == 2) return 2;
    if(dp[n] != 0) return dp[n];
    return dp[n] = countWays(n-1) + countWays(n-2);
}    