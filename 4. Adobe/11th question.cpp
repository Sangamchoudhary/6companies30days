
Time --> O(N)


class Solution{
    public:
    string amendSentence(string s){
        int n = s.length();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                ans.push_back(' ');
                ans.push_back(tolower(s[i]));
            }else{
                ans.push_back(s[i]);
            }
        }
        if(ans[0] == ' ')   ans.erase(ans.begin());
        return ans;
    }
};