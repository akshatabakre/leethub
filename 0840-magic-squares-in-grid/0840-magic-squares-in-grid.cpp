class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;(i+2)<n;i++){
            for(int j=0;j+2<m;j++){
                vector<int> nums(16,0);
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        nums[grid[i+ii][j+jj]]++;
                    }
                }
                bool valid = true;
                for(int x=1;x<10;x++){
                    if(nums[x]!=1){
                        valid = false;
                        break;
                    }
                }
                if(valid==false){
                    continue;
                }
                int sum = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                bool same = true;
                for(int ii=0;ii<3;ii++){
                    int s = 0;
                    for(int jj=0;jj<3;jj++){
                        s += grid[i+ii][j+jj];
                    }
                    if(s!=sum){
                        same = false;
                        break;
                    }
                }
                if(same){
                    for(int jj=0;jj<3;jj++){
                        int s = 0;
                        for(int ii=0;ii<3;ii++){
                            s += grid[i+ii][j+jj];
                        }
                        if(s!=sum){
                            same = false;
                            break;
                        }
                    }
                }
                if(same && sum==grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] && sum==grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2]){
                    ans++;
                }
            }
        }
        return ans;
    }
};