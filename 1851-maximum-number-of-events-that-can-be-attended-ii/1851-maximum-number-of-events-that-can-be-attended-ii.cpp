class Solution {
public:
    int maxReward(int ind,int k,vector<vector<int>>& events,vector<vector<int>> &dp,vector<int> &next){
        if(k==0 || ind>=events.size()){
            return 0;
        }
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int take = events[ind][2] + maxReward(next[ind],k-1,events,dp,next);
        int nottake = maxReward(ind+1,k,events,dp,next);
        return dp[ind][k] = max(take,nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int> next(n);
        for(int i=0;i<n;i++){
            int target = events[i][1];
            int s = i+1, e = n;
            while(s<e){
                int mid = s + (e-s)/2;
                if(events[mid][0]>target){
                    e = mid;
                }else{
                    s = mid+1;
                }
            }
            next[i] = s;
        }
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return maxReward(0,k,events,dp,next);
    }
};