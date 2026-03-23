#define ll long long
using state = pair<ll,ll>;

class Solution {
public:
    vector<vector<int>> grid;
    int n,m;
    ll mod = 1e9 + 7;
    vector<vector<state>> dp;
    vector<vector<bool>> vis;

    state solve(int i,int j){

        if(i>=n || j>=m){
            return {LLONG_MIN, LLONG_MAX};
        }

        if(i==n-1 && j==m-1){
            return {grid[i][j], grid[i][j]};
        }

        if(vis[i][j]){
            return dp[i][j];
        }

        vis[i][j] = true;
        state right = solve(i,j+1);
        state down = solve(i+1,j);

        ll curr = grid[i][j];

        ll maxi = LLONG_MIN;
        ll mini = LLONG_MAX;

        if(right.first != LLONG_MIN){
            maxi = max(maxi, curr * right.first);
            maxi = max(maxi, curr * right.second);

            mini = min(mini, curr * right.first);
            mini = min(mini, curr * right.second);
        }

        if(down.first != LLONG_MIN){
            maxi = max(maxi, curr * down.first);
            maxi = max(maxi, curr * down.second);

            mini = min(mini, curr * down.first);
            mini = min(mini, curr * down.second);
        }

        if(maxi == LLONG_MIN){
            return dp[i][j] = {LLONG_MIN, LLONG_MAX};
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();

        dp = vector<vector<state>>(n,vector<state>(m));
        vis = vector<vector<bool>>(n,vector<bool>(m,false));
        ll x = solve(0,0).first;

        if(x < 0) return -1;

        return x % mod;
    }
};