class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m =matrix.size(), n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        vector<int> res;
        while(up<=down && left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(matrix[up][j]);
            }
            up++;
            for(int i=up;i<=down;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(down>=up){
                for(int j=right;j>=left;j--){
                    res.push_back(matrix[down][j]);
                }
                down--;
            }
            if(left<=right){
                for(int i=down;i>=up;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};