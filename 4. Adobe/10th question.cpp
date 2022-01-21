
Time --> O( NlogN )
Space --> O(2N) , 1 for map and 1 for vector

class Solution{
  public:

    vector<string> winner(string arr[],int n){   
        int maxCount = INT_MIN;
        vector<string> ans;
        unordered_map<string,int> mp;

        for(int i=0;i<n;i++){
            string currStr = arr[i];
            int currCount = ++mp[currStr];
            maxCount = max(maxCount,currCount);
        }
        
        for(auto it : mp){
            if(it.second == maxCount){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(),ans.end());

        string ansStr = ans[0];
        string ansCount = to_string(maxCount);

        return {ansStr,ansCount};
    }
};