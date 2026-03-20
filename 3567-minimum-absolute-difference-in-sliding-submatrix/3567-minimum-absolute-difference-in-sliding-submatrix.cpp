class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                //i,j first point
                vector<int> distval;
                bool dup = false;
                unordered_set<int> vis;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        if(!vis.count(grid[x][y])){
                            distval.push_back(grid[x][y]);
                            vis.insert(grid[x][y]);
                        }else{
                            dup = true;
                        }
                    }
                }
                // for(int i:distval){
                //     cout<<i<<endl;
                // }
                sort(distval.begin(),distval.end());
                if(vis.size()==1){
                    ans[i][j] = 0;
                }else{
                    int mindiff = 1e9;
                    for(int ii=1;ii<distval.size();ii++){
                        mindiff = min(distval[ii]-distval[ii-1],mindiff);
                    }
                    ans[i][j] = mindiff;
                }
            }
        }

        return ans;
    }
};