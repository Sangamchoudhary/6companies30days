class Solution{
    public:
    void findMax(string &str,int k,string &ans){
        
        if(k == 0)  return;
        
        int n = str.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(str[j] > str[i]){
                    swap(str[i],str[j]);    
                    if (str.compare(ans) > 0)
                        ans = str;    
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