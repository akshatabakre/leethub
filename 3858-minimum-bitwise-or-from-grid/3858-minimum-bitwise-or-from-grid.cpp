class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> valid(m,vector<int>(n,1));
        for(int bit=31;bit>=0;bit--){
            for(int row=0;row<m;row++){
                bool found = false;
                for(int col=0;col<n;col++){
                    if(valid[row][col] && (grid[row][col] & (1<<bit))==0){
                        found = true;
                    }
                }
                if(!found){
                    ans = (ans|(1<<bit));
                    break;
                }
            }
            if((ans&(1<<bit))==0){
                for(int row=0;row<m;row++){
                    for(int col=0;col<n;col++){
                        if((grid[row][col]&(1<<bit))!=0){
                            valid[row][col] = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};