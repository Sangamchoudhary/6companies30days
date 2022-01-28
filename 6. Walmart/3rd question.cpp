class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        if(n < 3) return false;
        int i=0,j=0;
        int a=0,b=0;
        int count1=0,count2=0;
        
        while(j < n){
            if(j-i+1<3){
                if(colors[j] == 'A') count1++;
                else count2++;
            }else{
                if(colors[j] == 'A') count1++;
                else count2++;
                
                if(count1 == 3) a++,count1--;
                else if(count2 == 3) b++,count2--;
                else{
                    if(colors[i] == 'A') count1--;
                    else count2--;
                }
                i++;
            }
            j++;
        }
        
        bool res = (a > b);
        return res;
    }
};