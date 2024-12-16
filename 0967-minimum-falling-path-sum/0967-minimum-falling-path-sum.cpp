class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int ld = 1e6,rd=1e6,up;
                if(j>0)     ld = matrix[i][j] + v[j-1];
                up = matrix[i][j] + v[j];
                if(j<n-1)   rd = matrix[i][j] + v[j+1];
                temp[j] = min(up,min(ld,rd));
            }
            v = temp;
        }
        int ans = 1e6;
        for(int i=0;i<n;i++){
            ans = min(ans,v[i]);
        }
        return ans;
    }
};