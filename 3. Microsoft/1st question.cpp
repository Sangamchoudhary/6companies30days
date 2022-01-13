
let sum of array is K
let size of array is N

Time --> O(N*K)
Space --> O(N*K)

class Solution{

	public:
	int subsetsum(int arr[],int n,int sum){
	    
	    bool t[n+1][sum+1];
	    
	    for (int i = 0; i <= n; i++)
        t[i][0] = true;
 
        for (int i = 1; i <= sum; i++)
        t[0][i] = false;
	    
	    for(int i=1;i<n+1;i++)
	    for(int j=1;j<sum+1;j++){
	        
	        if(arr[i-1]<=j)
	        t[i][j]=( t[i-1][j-arr[i-1]] or t[i-1][j] );
	        
	        else
	        t[i][j]=t[i-1][j];
	    }
	    
	    for(int j=sum/2;j>=0;j--)
	        if(t[n][j])
	            return abs(sum-2*j);
	    
	}
	
	int minDiffernce(int arr[], int n) {   
    	int sum=0;
        sum = accumulate(arr,arr+n,sum); // sum of array
        return subsetsum(arr,n,sum);	        
	} 
};