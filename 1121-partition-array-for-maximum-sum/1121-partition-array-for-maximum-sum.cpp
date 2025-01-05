// #define ll long long
// #include<algorithm>
class Solution {
public:
    int f(int i,vector<int>& arr,int& k,vector<int>& dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxsum = 0, maxi = arr[i],n=arr.size();
        for(int ind=i;ind<min(n,i+k);ind++){
            // maxi = max(maxi,arr[ind]);
            if(maxi<arr[ind])   maxi = arr[ind];
            int sum = (ind-i+1)*maxi + f(ind+1,arr,k,dp);
            maxsum = max(sum,maxsum);
        }
        return dp[i] = maxsum;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return f(0,arr,k,dp);
    }
};