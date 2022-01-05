
Language --> C++

Time --> O(N) , as we are visiting element at most 2 time 
Space --> O(1) , No extra space required

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        
        for(int i=1;i<=n-2;){
            if(arr[i] > arr[i+1] and arr[i] > arr[i-1]){
                int j = i;
                int length = 1;
                while(j > 0 and arr[j] > arr[j-1]){
                    j--;
                    length++;
                }
                i++;
                while(i <= n-1 and arr[i] < arr[i-1]){
                    i++;
                    length++;
                }
                ans = max(ans,length);
            }else{
                i++;
            }
        }
        return ans;
    }
};