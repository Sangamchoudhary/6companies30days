
Time --> O(N^2)
Space --> O(N^2)

class Solution{
  public:
    int subset(int arr[],int &n,int &sum){
        
        bool t[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
             t[i][0] = true;
             
        for(int i=1;i<=sum;i++)
             t[0][i] = false;
            
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j] or t[i-1][j - arr[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        for(int i = sum/2;i>=0;i--)
            if(t[n][i])
                return abs(sum - 2*i);
    }
  
	int minDifference(int arr[], int n){ 
	    int sum = accumulate(arr,arr+n,0); //find sum of array
	    return subset(arr,n,sum);
	} 
};