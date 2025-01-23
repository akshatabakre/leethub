class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> vertical(n,0), horizontal(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vertical[j]++;
                    horizontal[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            vertical[i] = (vertical[i]>1)? 1 : 0;
        }
        for(int i=0;i<m;i++){
            horizontal[i] = (horizontal[i]>1)? 1 : 0;
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (vertical[j]||horizontal[i])){
                    ans++;
                }
            }
        }
        return ans;
    }
};