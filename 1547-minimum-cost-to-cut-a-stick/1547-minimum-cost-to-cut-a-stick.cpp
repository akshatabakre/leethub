class Solution {
public:
    vector<int> cuts;
    vector<vector<int>> dp;
    int cost(int l,int r){
        if(l+1==r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int mini = 1e9;
        for(int i=l+1;i<r;i++){
            mini = min(cuts[r]-cuts[l]+cost(l,i)+cost(i,r),mini);
        }
        return dp[l][r] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        this->cuts = cuts;
        this->cuts.push_back(0);
        this->cuts.push_back(n);
        sort(this->cuts.begin(),this->cuts.end());
        int m = this->cuts.size();
        dp.resize(m,vector<int>(m,-1));
        return cost(0,this->cuts.size()-1);
    }
};