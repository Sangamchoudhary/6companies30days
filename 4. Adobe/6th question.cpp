
Time --> O(2^N)
Aux Space --> O(N)

class Solution {
public:
    
    void createBracket(int open,int close,int n,string str,vector<string> &ans){
        
        if(open > n){
            return;
        }else if(open == n and close == 0){
            ans.push_back(str);
            return;
        }
        
        createBracket(open+1,close+1,n,str + '(',ans);
        if(close > 0)   
        createBracket(open,close-1,n,str + ')',ans);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        createBracket(0,0,n,"",ans);
        return ans;
    }
};