class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = -1;
        long long ans = 0;
        while(l<n){
            while(r+1<n && (r==l-1 || prices[r+1]-prices[r]==-1)){
                r++;
            }
            ans+=(r-l+1);
            if(r<=l){
                l++;
                r = l-1;
            }else{
                l++;
            }
        }
        return ans;
    }
};