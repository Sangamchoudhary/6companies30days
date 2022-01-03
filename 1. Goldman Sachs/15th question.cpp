
Language --> C++

Time --> O(N) 
Space --> O(N) for unordered_map

There are 2 version of this question 

1. when only +ve no are in array
2. when -ve no. can be present

solution for 1st version

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int> mp;
        int n = arr.size();
        if(n % 2 != 0) return false;
        
        for(int i=0;i<n;i++){
            mp[( (arr[i] % k) + k) % k]++;
        }
        for(int i=0;i<n;i++){
            
            int rem1 = arr[i] % k;
            
            if(rem1 == 0){
                if(mp[rem1] % 2 != 0) return false;
            }
            else{
                int rem2 = k - rem1;
                if(mp[rem1] != mp[rem2]) return false;
            }
            
        }
        return true;            
    }
};

Solution for 2nd version

class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        
        unordered_map<int,int> mp;
        
        int n = arr.size();
        if(n % 2 != 0) return false;
        
        for(int i=0;i<n;i++){
            mp[arr[i] % k]++;
        }
        
        for(int i=0;i<n;i++){
            
            int rem1 = arr[i] % k;
            
            if(rem1 == 0){
                if(mp[rem1] % 2 != 0) return false;
            }
            else{
                int rem2 = k - rem1;
                if(rem1 == rem2 and mp[rem1] % 2 != 0) return false;
                if(mp.find(rem2) == mp.end()) return false;
                if(mp[rem1] != mp[rem2]) return false;
            }
            
        }
        return true;
    }
};