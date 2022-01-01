let length of max string is 'm'

Time Complexity 
--> O(n * n*(size of max string) ) ---> O(n^2 * m)

Space Complexity

--> 1 unordered_set - O(n)
--> 2 unordered_map - O(m + m)
--> final space will be -> O(n + 2m)

📲 can easily be solved with 1 map also


class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& str) {
        vector<vector<string>> ans;
        unordered_set<int> block;
        int n = str.size();
        for(int i=0;i<n;i++){ // time consume
            if(block.find(i) != block.end()) continue;
            vector<string> tempAns;
            tempAns.push_back(str[i]);
            unordered_map<char,int> mp1;
            for(auto it:str[i]){ //time consume
                mp1[it]++;
            }
            for(int j=i+1;j<n;j++){ //time consume
                unordered_map<char,int> mp2;
                for(auto it:str[j]){ //time consume
                    mp2[it]++;
                }
                if(mp1 == mp2){ //time consume
                    block.insert(j);
                    tempAns.push_back(str[j]);
                }
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};