class Solution {
public:
    bool isEqual(vector<vector<int>>&mat,vector<vector<int>>&tar){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=tar[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0;i<4;i++){
            if(isEqual(mat,target)){
                return true;
            }
            //transpose
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            //reverse rows
            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
        }
        return false;
    }
};