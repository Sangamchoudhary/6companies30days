
Time --> O(N)
Space --> O(1)

class Solution{
  public:
    int atoi(string s) {
        int i=0 , n = s.length();
        int sign = 1;
        
        while(i < n and s[i] == ' ') i++;
        
        if(i < n and s[i] == '-') sign = -1 , i++;
        else if(i < n and s[i] == '+') i++;
        
        if(s[i] < '0' or s[i] > '9') return -1;
        
        int ans = 0;
        
        while(i < n and s[i] >= '0' and s[i] <= '9'){
            
            if(ans > INT_MAX/10  or  (ans  == INT_MAX/10 and s[i] > '7'))
                return sign == 1 ? INT_MAX : INT_MIN;
                
            ans *= 10;
            ans += (s[i] - '0');
            i++;
            
        }
        if(i < n) return -1;
        
        ans *= sign;
        
        return ans;
    }
};