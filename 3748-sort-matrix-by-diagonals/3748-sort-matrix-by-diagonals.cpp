class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,multiset<int>> mp;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i-j].insert(grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i-j>=0){
                    auto it = prev(mp[i - j].end());
                    grid[i][j] = *it;
                    mp[i - j].erase(it);
                }else{
                    auto it = mp[i-j].begin();
                    grid[i][j] = *it;
                    mp[i-j].erase(it);
                }
            }
        }
        return grid;
    }
};