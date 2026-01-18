class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rowsum(m,vector<int>(n,0)),colsum(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            rowsum[i][0] = grid[i][0];
            for(int j=1;j<n;j++){
                rowsum[i][j] = rowsum[i][j-1] + grid[i][j];
            }
        }
        for(int j=0;j<n;j++){
            colsum[0][j] = grid[0][j];
            for(int i=1;i<m;i++){
                colsum[i][j] = colsum[i-1][j] + grid[i][j];
            }
        }
        for(int len=min(m,n);len>=1;len--){
            for(int i=0;i+len<m;i++){
                for(int j=0;j+len<n;j++){
                    int prev = 0;
                    if(j){
                        prev = rowsum[i][j-1];
                    }
                    bool valid = true;
                    int rs = rowsum[i][j+len]-prev;
                    for(int k=1;k<=len;k++){
                        if(j)
                        prev = rowsum[i+k][j-1];
                        if(rs!=rowsum[i+k][j+len]-prev){
                            valid = false;
                            break;
                        }
                    }
                    if(!valid){
                        continue;
                    }
                    prev = 0;
                    if(i){
                        prev = colsum[i-1][j];
                    }
                    int cs = colsum[i+len][j] - prev;
                    for(int k=1;k<=len;k++){
                        if(i)
                        prev = colsum[i-1][j+k];
                        if(cs!=colsum[i+len][j+k]-prev){
                            valid = false;
                            break;
                        }
                    }
                    if(!valid || cs!=rs){
                        continue;
                    }
                    int dg1 = 0, dg2 = 0;
                    for(int k=0;k<=len;k++){
                        dg1+=grid[i+k][j+k];
                        dg2+=grid[i+k][j+len-k];
                    }
                    if(dg1==dg2 && dg1==rs && rs==cs){
                        return len+1;
                    }
                }
            }
        }
        return 1;
    }
};