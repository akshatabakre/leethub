class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());
        // for(auto it:v){
        //     cout<<it[0]<<" "<<it[1];
        // }
        // cout<<endl;
        vector<int> pm(n);
        pm[0] = v[0][1];
        // cout<<pm[0]<<endl;
        for(int i=1;i<n;i++){
            pm[i] = max(v[i][1],pm[i-1]);
            // cout<<pm[i]<<" ";
        }
        // cout<<endl;
        sort(costs.begin(),costs.end());
        for(int i=0;i<n;i++){
            // cout<<costs[i]<<" "<<v[i][1]<<endl;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int lb = lower_bound(costs.begin(),costs.begin()+i,budget-costs[i])-costs.begin();
            if(lb==0){
                if(v[i][0]<budget)
                ans = max(ans,v[i][1]);
                cout<<i<<" "<<ans<<endl;
            }else{
                lb--;
                if(i==1){
                    // cout<<pm[lb]<<endl;
                }
                if(budget>v[i][0])
                ans = max(ans,v[i][1]+pm[lb]);
            }
        }
        return ans;
    }
};