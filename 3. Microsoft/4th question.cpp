
Time --> O(N^2)
Space --> O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat){
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        
        int minRow = 0 , maxRow = m-1;
        int minCol = 0, maxCol = n-1;
        int cnt = 0 , tne = m*n; //tne --> total no of elements
        
        while(cnt < tne){
            
            //top row
            for(int i = minRow , j = minCol ; j <= maxCol and cnt < tne; j++){
                ans.push_back(mat[i][j]);
                cnt++;
            }
            minRow++;
            
            //right col
            for(int i = minRow , j = maxCol ; i <= maxRow and cnt < tne ; i++){
                ans.push_back(mat[i][j]);
                cnt++;
            }
            maxCol--;        
            
            //bottom row
            for(int i = maxRow , j = maxCol ; j >= minCol and cnt < tne ; j--){
                ans.push_back(mat[i][j]);
                cnt++;
            }
            maxRow--;                    
            
            //left col
            for(int i = maxRow , j = minCol ; i >= minRow and cnt < tne ; i--){
                ans.push_back(mat[i][j]);
                cnt++;
            }
            minCol++;                    
            
        }
        return ans;
    }
};