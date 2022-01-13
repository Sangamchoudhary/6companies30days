
Time --> O(N^3)
Space --> O(1)

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size()-3; i++){
            for(int j = i+1; j < arr.size()-2; j++){
                int l = j+1 , r = arr.size()-1;
                while(l < r){
                    int sum = arr[i]+arr[j]+arr[l]+arr[r];
                    if(sum == k){
                        v.push_back({arr[i],arr[j],arr[l],arr[r]});
                        l++;
                        r--;
                    }
                    else if(sum < k)
                        l++;
                    else
                        r--;
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};