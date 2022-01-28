
Time --> O(N^2)
Aux Space --> O(N^2)

class Solution{
    public:
    long long t[101][101];
    int mod = 1e9 + 7;
    long long countPath(int m,int n){
        if(m == 1 or n==1)  return 1;
        
        if(t[m][n] != -1)   return t[m][n];
        
        int option1 = countPath(m-1,n);
        int option2 = countPath(m,n-1);
        
        int ans = (option1 + option2) % mod;
        
        return t[m][n] = ans;
    }    
    int NumberOfPath(int a, int b){
        memset(t,-1,sizeof t);
        return countPath(a,b);
    }
};