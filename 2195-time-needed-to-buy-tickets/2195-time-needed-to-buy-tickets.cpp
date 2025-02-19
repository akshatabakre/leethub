class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int n = tickets.size();
        for(int i=0;i<=k;i++){
            ans+=min(tickets[k],tickets[i]);
        }
        if(k+1<n){
            for(int i=k+1;i<n;i++){
                ans+=min(tickets[k]-1,tickets[i]);
            }
        }
        return ans;
    }
};