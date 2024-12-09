class Solution {
public:
    bool isV(vector<vector<int>>& matrix,int row,int col,int num){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][col]==num && i!=row){
                return false;
            }
            if(matrix[row][i]==num && i!=col){
                return false;
            }
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!isV(matrix,i,j,matrix[i][j]))
                    return false;
            }
        }
        return true;
    }
};