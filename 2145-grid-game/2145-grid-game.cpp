#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        vector<vector<ll>> ps(2,vector<ll>(n+1,0));
        ps[0][1] = grid[0][0], ps[1][1] = grid[1][0];
        for(int i=2;i<=n;i++){
            ps[0][i] = grid[0][i-1] + ps[0][i-1];
            ps[1][i] = grid[1][i-1] + ps[1][i-1];
        }
        for(int i=0;i<=n;i++){
            cout<<ps[0][i]<<" ";
        }   cout<<endl;
        for(int i=0;i<=n;i++){
            cout<<ps[1][i]<<" ";
        }
        ll minmax = LLONG_MAX;
        for(int i=1;i<=n;i++){
            cout<<ps[0][n] - ps[0][i]<<" "<<ps[1][i-1]<<endl;
            ll maxi = max(ps[0][n] - ps[0][i],ps[1][i-1]);
            minmax = min(maxi,minmax);
        }
        return minmax;
    }
};