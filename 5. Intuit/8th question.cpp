
Time --> O(NlogN)
Space --> O(N) , for map

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int ans = 0;
        
        for(auto &it : points){
            map<double,int> mp;
            
            auto x1 = it[0];
            auto y1 = it[1];
             
            for(auto &i : points){
                
                if(i == it) continue;
                
                auto x2 = i[0];
                auto y2 = i[1];
                
                int xdist = (x1 - x2) * (x1 - x2);
                int ydist = (y1 - y2) * (y1 - y2);
                
                double finalDist = sqrt(xdist + ydist);
                
                mp[finalDist]++;
            }
            
            for(auto &i : mp) if(i.second > 1) ans += (i.second * (i.second-1));
            
        }
        
        return ans;
    }
};