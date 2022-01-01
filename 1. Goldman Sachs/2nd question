Time --> O(1)
Space --> O(1)

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) { 
        
        //varibles are just for my understanding     
        int l1x = L1[0];
        int l1y = L1[1];
        int r1x = R1[0];
        int r1y = R1[1];
        
        int l2x = L2[0];
        int l2y = L2[1];
        int r2x = R2[0];
        int r2y = R2[1];
        
        if(l2x > r1x or r2x < l1x){
            return false;
        }else if(r1y > l2y or l1y < r2y){
            return false;
        }
        
        return true;
    }
};