class Solution {
public:
    int divide(int dividend, int divisor) {
            
            if(dividend==divisor)
                    return 1;
             int sign=(dividend>=0&&divisor>=0)||(dividend<0&&divisor<0)?1:-1;
            
            // unsigned to store overflow for max negative value
            unsigned int dividendAbsValue=abs(dividend);
            unsigned int divisorAbsValue=abs(divisor);
            unsigned int quotient=0;
            /*
            eg divident=10 and divisor=3
                10=3*(2^0+2^1)+1
                quotient=(2^0+2^1)
            
            */
            // while 10>3
            while(dividendAbsValue>=divisorAbsValue)
            {
                    int countShiftLeft=0;
                    // 3*(2^countshiftLeft+1)
                    while(dividendAbsValue>(divisorAbsValue<<(countShiftLeft+1)))
                            countShiftLeft++;
                    // quotient+=2^countShiftLeft
                    quotient+=1<<countShiftLeft;
                    // 10-3*(2^countshiftLeft)
                    dividendAbsValue-=divisorAbsValue<<countShiftLeft;
                    
            }
            
            // checking overflow
            if(quotient==1<<31&&sign==1)
                    return INT_MAX;
            return quotient*sign;
                     
    }
};