
Time --> O(logN)
Aux Space --> O(logN)

#define mod 1000000007
class Solution{
    public:
    
    long long power1(int n,int r){
        if(r <= 0) return 1;
        
        long long ans;
        long long pw = power1(n,r/2);
        long long res = (pw * pw) % mod;
        if(r % 2 == 0){
            ans = res;
        }else{
            ans = (n * res) % mod;
        }
        
        return ans;
    }
    
    long long power(int N,int R){
        long long ans = power1(N,R);  
        return (long long)ans;
    }
};