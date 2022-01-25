
Time --> O(NlogN)
Space --> O(1)

class Solution {
public:
    
    bool isPossible(int mid,vector<int> &arr,int days){
        int count = 1;
        int weight = 0;
        for(auto &it : arr){
            weight += it;
            if(weight > mid){
                weight = it;
                count++;
            }
        }
        return count <= days;
    }
    
    int shipWithinDays(vector<int>& arr, int days){
        
        int sum = accumulate(arr.begin(),arr.end(),0);
        int i = *max_element(arr.begin(),arr.end());
        int j = sum;
        int ans;
        
        while(i <= j){
            int mid = (i + j)/2;
            
            if(isPossible(mid,arr,days)){
                ans = mid;
                j = mid - 1;
            }else{
                i = mid + 1;
            }
            
        }
        
        return ans;
    }
};