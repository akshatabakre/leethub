class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> p(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[i][j] = mat[i][j];
                if(i)
                    p[i][j]+=p[i-1][j];
                if(j)
                    p[i][j]+=p[i][j-1];
                if(i && j){
                    p[i][j]-=p[i-1][j-1];
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<p[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int len = min(m,n);len>=0;len--){
            for(int i=0;i+len<m;i++){
                for(int j=0;j+len<n;j++){
                    int s = p[i+len][j+len];
                    if(i){
                        s-=p[i-1][j+len];
                    }
                    if(j){
                        s-=p[i+len][j-1];
                    }
                    if(i && j){
                        s+=p[i-1][j-1];
                    }
                    if(s<=threshold){
                        // cout<<s<<" "<<i<<" "<<j<<endl;
                        return len+1;
                    }
                }
            }
        }
        return 0;
    }
};