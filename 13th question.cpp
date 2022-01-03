
Language --> C++

Time --> O(N) ,as we are only traversing our array once 

Space --> O(1) , ans string will not be count as an extra space
Aux Space -->O(N) , In worst case we have to store everyhting in our aux. stack

class Solution {
public:
    bool isNum(char a){
        return (a >= '0' and a <= '9');
    }
    
    bool isAlphabet(char a){
        return (a >= 'a' and a <= 'z');
    }

    string solve(string &s,int &n,int &i){
        string ans = "";
        int num = 0;
        for(;i<n;i++){
            // if we get a number
            if(isNum(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            // we can get an open bracket
            else if(s[i] == '['){
                i++;
                string temp = solve(s,n,i);
                while(num--)    
                    ans += temp;
                num = 0;
            }
            // we can get a close bracket
            else if(s[i] == ']'){
                return ans;
            }
            // we can get alphabets
            else{
                ans += s[i];
            }
        }
        return ans;
    }

    string decodeString(string s){
        int i=0,n=s.length();
        return solve(s,n,i);
    }  
};

