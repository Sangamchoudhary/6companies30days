
Time --> O(NlogN)
Space --> O(M + 2N)

class Solution {
  public:
    const int INF = 1e9 + 5;
    int lis(vector<int> a) {
        int n = a.size();
        vector<int> len;
        for(int i = 0; i < n; i++) {
            auto lb = lower_bound(len.begin(), len.end(), a[i]);
            if(lb != len.end()) {
                *lb = min(*lb, a[i]);
            }
            else {
                len.push_back(a[i]);
            }
        }
        return len.size();
    }
    int minInsAndDel(int a[], int b[], int n, int m) {
        unordered_set<int> b_set;
        for(int i = 0; i < m; i++) 
            b_set.insert(b[i]);
        vector<int> a_updated;
        int steps = 0;
        for(int i = 0; i < n; i++) {
            if(b_set.find(a[i]) != b_set.end()) {
                a_updated.push_back(a[i]);
            }
            else {
                steps++;
            }
        }
        int lis_size = lis(a_updated);
                //delete + delete +   insert
        return steps + (a_updated.size() - lis_size) + (m-lis_size);
    }
};


Time --> O(N^2)
Space --> O(N^2)

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        int t[N+1][M+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                if(i == 0 or j == 0) t[i][j] = 0;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(A[i-1] == B[j-1])    
                    t[i][j] = 1 + t[i-1][j-1];
                else 
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
        int lcsLength = t[N][M];
        
        int insertion = M - lcsLength;
        int deletion = N  - lcsLength;
        
        return insertion + deletion;
    }
};