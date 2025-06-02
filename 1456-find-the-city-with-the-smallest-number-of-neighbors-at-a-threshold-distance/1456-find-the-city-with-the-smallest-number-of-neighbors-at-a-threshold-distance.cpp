class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> distance(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++)    distance[i][i] = 0;
        for(auto edge:edges){
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][via]==1e8 || distance[via][j]==1e8){
                        continue;
                    }
                    distance[i][j] = min(distance[i][via]+distance[via][j],distance[i][j]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<distance[i][j]<<" ";
        //     cout<<endl;
        // }
        int ans = -1;
        int mincount = n;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(distance[i][j]<=dt && i!=j){
                    count++;
                }
            }
            // cout<<i<<" "<<count<<endl;
            if(mincount>=count){
                mincount = count;
                ans = i;
            }
        }
        return ans;
    }
};