
Time --> O(N)
Space --> O(1)

class Solution{
    public:
    vector<int> subarraySum(int arr[], int n, long long s){
        int i=0,j=0;
        int sum = 0;
        while(j < n){
            sum += arr[j];
            if(sum > s){
                while(i <= j and sum > s){
                    sum -= arr[i];
                    i++;
                }
            }
            if(sum == s){
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
};