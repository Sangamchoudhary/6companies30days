
Time --> O(N^2)
Space --> O(1)

void rotate(vector<vector<int> >& mat){       
        int n = mat.size();
        
        // accessing only (n(n+1)/2) elements 
        // i.e in 4*4 matrix we access only 10 elements out of 16 elements
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        // swap vector (N/2 * (N))
        for(int i=0;i<n/2;i++){
            swap(mat[i],mat[n-1-i]);
        }
        
}