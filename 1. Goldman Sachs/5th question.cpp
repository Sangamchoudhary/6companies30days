
Language --> c++

Time --> O(N)
Space --> O(N) to store all ugly numbers till N


class Solution{
public:	
	ull getNthUglyNo(int n) {
	    vector<ull> dp;
	    dp.push_back(1);
	    int two=0,three=0,five=0;
	    int cnt = 0;
	    while(true){
	        ull mini = min({2*dp[two] , 3*dp[three] , 5*dp[five]});
	        dp.push_back(mini);
	        if(mini == 2*dp[two]) two++;
	        if(mini == 3*dp[three]) three++;
	        if(mini == 5*dp[five]) five++;
	        cnt++;
	        if(cnt == n-1) break;
	    }
	    return dp.back();
	}
};