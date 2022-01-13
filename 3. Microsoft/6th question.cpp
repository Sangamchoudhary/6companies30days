
Time --> O(N * (4^N) )
Space --> O(8*4) , for storing keypad values
Aux Spac --> (4^N)

class Solution{
    public:
    void print(int i,int arr[],vector<vector<char>>&dict,int n,vector<string>&ans,string str){
        
        if(i >= n){
            ans.push_back(str);
            return;
        }
        
        int currSize = dict[arr[i]-2].size();
        
        for(int j=0;j<currSize;j++){
            print(i+1,arr,dict,n,ans,str + dict[arr[i]-2][j]);
        }
    }
    
    vector<string> possibleWords(int arr[], int n){
        vector<string> ans;
        vector<vector<char>> dict;
        dict.push_back({'a','b','c'});
        dict.push_back({'d','e','f'});
        dict.push_back({'g','h','i'});
        dict.push_back({'j','k','l'});
        dict.push_back({'m','n','o'});
        dict.push_back({'p','q','r','s'});
        dict.push_back({'t','u','v'});
        dict.push_back({'w','x','y','z'});
        
        print(0,arr,dict,n,ans,"");
        
        return ans;
    }
};