
Time --> O(NlogN)
Space --> O(1)

class Solution {
public:
    
    bool isValid(int mid,vector<int> &arr,int m){
        int sum = 0, count = 1;
        
        for(auto &it : arr){
            
            sum += it;

            if(sum > mid)   sum = it, count++;
            
        }
        
        return count <= m;
    }
    
    int splitArray(vector<int>& arr, int m) {
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        int low = *max_element(arr.begin(),arr.end()) , high = sum;
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isValid(mid,arr,m)) ans = mid , high = mid - 1;
            
            else    low = mid + 1;
        }
        
        return ans;
    }
};