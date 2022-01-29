
Time --> O(NlogN)
Space --> O(N + K)

class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>> v;
        
        for(int i = 0;i<n;i++){
            v.push_back({eff[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum = 0, res = 0;
        
        for(int i=n-1;i>=0;i--){
            int ele = v[i].second;
            sum += ele;
            pq.push(ele);
            
            if(pq.size() > k) sum -= pq.top(), pq.pop();
            
            int top = v[i].first;
            
            res = max(res,sum * top);
        }
        
        return res % mod;
    }
};