class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool forward = true;
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            if(forward){
                for(int j=0;j<m;j+=2){
                    ans.push_back(grid[i][j]);
                }
            }else{
                int s = m-1;
                if(m%2==1){
                    s--;
                }
                for(int j=s;j>=0;j-=2){
                    ans.push_back(grid[i][j]);
                }
            }
            forward = !forward;
        }
        return ans;
    }
};