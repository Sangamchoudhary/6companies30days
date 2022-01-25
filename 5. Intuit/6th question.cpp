
Time --> O(logN)
Space --> O(1)

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int i=0,j=n-1;
        int peak;
        
        while(i <= j){
            int mid = i + (j-i)/2;
            
            int pre = -1,post = -1,ele = -1;
            
            ele = arr.get(mid);
            if(mid - 1 >= 0) pre = arr.get(mid-1);
            if(mid + 1 < n) post = arr.get(mid+1);
            
            if(ele > pre and ele > post){
                peak = mid;
                if(ele == target) return mid;
                break;
            }
            else if(ele > pre)  i = mid + 1;
            else    j = mid - 1;
        }
        
        int low1 = 0 , high1 = peak-1;
        
        while(low1 <= high1){
            int mid = (low1 + high1)/2;
            
            int ele = arr.get(mid);
            
            if(ele == target) return mid;
            else if(ele > target) high1 = mid - 1;
            else low1 = mid + 1;
        }
        
        int low2 = peak+1 , high2 = n-1;
        
        while(low2 <= high2){
            int mid = (low2 + high2)/2;
            
            int ele = arr.get(mid);
            
            if(ele == target) return mid;
            else if(ele > target) low2 = mid + 1;
            else high2 = mid - 1;            
        }
        
        return -1;
        
    }
};