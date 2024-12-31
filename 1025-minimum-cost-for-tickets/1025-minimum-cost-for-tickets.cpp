class Solution {
public:
    // int f(int ind,vector<int>& d, vector<int>& c,vector<int>& dp){
    //     if(ind>=d.size()){
    //         return 0;
    //     }
    //     if(ind==d.size()-1){
    //         return min(c[0],min(c[1],c[2]));
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     int nId = d.size();
    //     while(d[nId-1]>d[ind]+29){
    //         nId--;
    //     }
    //     int pass30 = c[2] + f(nId,d,c,dp);
    //     while(d[nId-1]>d[ind]+6){
    //         nId--;
    //     }
    //     int pass7 = c[1] + f(nId,d,c,dp);
    //     int pass1 = c[0] + f(ind+1,d,c,dp);
    //     return dp[ind] = min(pass1,min(pass7,pass30));
    // }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        int n = d.size();
        vector<int> dp(n+1,0);
        // return f(0,d,c,dp);
        int mincost = min(c[0],min(c[1],c[2]));
        dp[n] = 0;
        dp[n-1] = mincost;
        for(int i=n-2;i>=0;i--){
            int nid = n;
            while(d[nid-1]>d[i]+29){
                nid--;
            }
            int pass30 = dp[nid];
            while(d[nid-1]>d[i]+6){
                nid--;
            }
            int pass7 = dp[nid];
            int pass1 = dp[i+1];
            dp[i] = min(c[0]+pass1,min(c[1]+pass7,c[2]+pass30));
        }
        return dp[0];
    }
};