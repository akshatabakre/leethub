class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int,vector<int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<m+n-1;i++){
            if(i%2==0){
                reverse(mp[i].begin(),mp[i].end());
            }
            for(auto j:mp[i]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};