class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> w(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(j-1>=0){
                        w[i][j]=1+w[i][j-1];
                    }
                    else{
                        w[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                int mini=w[i][j];
                for(int k=i;k>=0;k--){
                    ans+=min(mini,w[k][j]);
                    mini=min(mini,w[k][j]);
                    if(mini==0){
                        break;
                    }
                }
                }
            }
        }
        return ans;

        
    }
};