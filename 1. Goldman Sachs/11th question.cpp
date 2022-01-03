
Language --> c++

Time --> O(N)
Space --> O(1) , as answer array will note be included in extra space

class Solution{
public:
    int *findTwoElement(int *arr, int n) {

        int *ans = new int[2];

        for(int i=0;i<n;i++){
            arr[abs(arr[i]) - 1] *= -1;
        }

        int idx=0;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                ans[idx] = i+1;
                idx++;
            } 
        }

        int first = ans[0],second = ans[1],count = 0;

        for(int i=0;i<n;i++){
            if(abs(arr[i]) == first) count++;
        }

        if(count == 0){
            ans[0] = second;
            ans[1] = first;
        }

        return ans;
    }
};