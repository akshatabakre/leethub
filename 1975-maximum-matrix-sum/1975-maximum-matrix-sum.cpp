class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        #define int long long
        int n = matrix.size();
        int sum = 0;
        int minabs = 1e9;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                minabs = min((long long)abs(matrix[i][j]),minabs);
                if(matrix[i][j]<=0){
                    cnt++;
                }
            }
        }
        if(cnt%2 && minabs!=1e9){
            sum-=(2*minabs);
        }
        return sum;
        #undef int
    }
};