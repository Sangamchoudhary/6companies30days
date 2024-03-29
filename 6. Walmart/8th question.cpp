
Time --> O(1)
Space --> O(1)

class Solution{
public:
    int height(int n){
        // n * (n + 1)/2  = x
        // n * (n + 1) = 2x
        // n^2 + n - 2x = 0;
        // as we know ax^2 + bx + c = 0
        // after compairing both eqn a = 1,b = 1, c= 2x(x is the input we are getting in hegith funtion)
        // D = b^2 - 4ac
        // root of eqn i.e n = (-b +- sqrt(b^2 - 4ac)) / 2a;
        // so now here we are with our final eqn to get the requires solution
        
        int ans = (-1 + sqrt(1 + (8*n))) / 2;
        return ans;
    }
};