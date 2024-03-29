
Time --> O(N^2)
Space --> O(N^2)

class Solution{
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum % 2) return false;
        
        bool dp[n+1][sum/2 + 1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum/2;j++){
                
                if(i == 0)  dp[0][j] = false;
                if(j == 0)  dp[i][0] = true;
                
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                
                if(nums[i-1] <= j)  
                    dp[i][j] = dp[i - 1][j - nums[i-1]] or dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];                
                
            }
        }
        
        return dp[n][sum/2];
    }
};