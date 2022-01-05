
Language --> C++


Let k be the total transaction allowed

Time Complexity
==> O(K * (N * (N)) ) 
==> O(K * N^2)

Space --> O(K*N) ,for out t matrix

Code 👇

class Solution {
  public:
  
    int maxProfit(int k, int n, int arr[]) {
        if(k == 0 or n == 0) return 0;
        
        int t[k+1][n];
        
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i == 0 or j == 0){
                    t[i][j] = 0;
                }
                else{
                    t[i][j] = t[i][j-1];
                    
                    int s = j - 1;
                    while(s >= 0){
                        t[i][j] = max(t[i][j] , (arr[j] - arr[s]) + t[i-1][s]);
                        s--;
                    }
                }
            }
        }
        
        return t[k][n-1];
    }
};