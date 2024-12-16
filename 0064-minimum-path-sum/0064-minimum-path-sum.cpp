class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //space optimization
        vector<int> v(n);
        //base case initialization
        v[0] = grid[0][0];
        for(int i=1;i<n;i++){
            v[i] = v[i-1] + grid[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int up = v[j],left = INT_MAX;
                if(j>0){
                    left = temp[j-1];
                }
                temp[j] = grid[i][j] + min(up,left);
            }
            v = temp;
        }
        return v[n-1];
    }
};