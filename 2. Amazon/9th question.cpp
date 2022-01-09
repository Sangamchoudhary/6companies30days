
Language --> C++

Time --> O(N^3)
Space --> O(N)
Aux Space --> O(1)

class Solution{
public:
    bool validateSubgrid(vector<vector<int>> &mat,int i,int j){
        int freq[10] = {0};
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                freq[mat[x][y]]++;            
            }
        }
        for(int x=1;x<=9;x++){
            if(freq[x] > 1)
                return false;
        }
        return true;
    }
    bool validRowAndCol(vector<vector<int>> &mat,int k){
        //for row
        int freq[10] = {0};
        for(int i=0;i<9;i++){
            freq[mat[i][k]]++;
        }
        for(int i=1;i<=9;i++){
            if(freq[i] > 1){
                return false;
            }
            freq[i] = 0;
        }
        //for col
        for(int i=0;i<9;i++){
            freq[mat[k][i]]++;
        }
        for(int i=1;i<=9;i++){
            if(freq[i] > 1){
                return false;
            }
            freq[i] = 0;
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        bool flag = 1;
        for(int i=0;i<9;i++){
            if(!validRowAndCol(mat,i)){
                return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!validateSubgrid(mat,i,j))
                    return 0;
            }
        }
        
        return 1;
    }
};