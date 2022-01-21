
Time --> O(N)
Space --> O(1)

class Solution{
    public:
    vector<int> leaders(int arr[], int n){
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(maxi <= arr[i]){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};