
Language --> C++

Time Complexity --> O(N) as Every element in the array is accessed at most two times
Space Comlexity --> O(1),as we are not using any extra space

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        int i=0,j=0,ans=0;
        long long prod = 1;
        while(j < n){
            prod *= arr[j];
            if(prod >= k){
                while(i <= j and prod >= k){
                    prod /= arr[i];
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};