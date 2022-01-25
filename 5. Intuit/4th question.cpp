
Time --> O(N^2 * K)
Space -->  O(N)

class Solution{
    public:
    bool isMax(string &str,string &ans,int n){
        int i = 0;
        while(i < n){
            if(str[i] > ans[i]) return true;
            else if(str[i]< ans[i]) return false;
            i++;
        }
        return false;
    }
    void findMax(string &str,int k,string &ans){
        
        if(k == 0)  return;
        
        int n = str.size();
        for(int i=0;i<n-1;i++){
            
            for(int j=i+1;j<n;j++){
                
                if(str[j] > str[i]){
                    swap(str[i],str[j]);
                    
                    if(isMax(str,ans,n))  ans = str;
                    
                    findMax(str,k-1,ans);
                    
                    swap(str[i],str[j]);
                }
                
            }
            
        }    
    }
    
    string findMaximumNum(string str, int k){
        string ans = str;
        findMax(str,k,ans);
        return ans;
    }
};