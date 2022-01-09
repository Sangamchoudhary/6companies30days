
Language --> C++

Time --> O(logN)
Explanation --> as we are always doing n/26;

Space --> O(1)

class Solution{
    public:
    string colName (long long int n){
        string s;
        while(n--){
            int r = n % 26;
            s.push_back(r + 'A');
            n /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};