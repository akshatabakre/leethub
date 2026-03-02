class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> f;
        map<int,int> ftomini;
        for(int i:nums) f[i]++;
        for(auto it:f){
            if(ftomini.find(it.second)==ftomini.end()){
                ftomini[it.second] = 1e9;
            }
            ftomini[it.second] = min(it.first,ftomini[it.second]);
        }
        for(auto it:ftomini){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int> ans(2,1e9);
        for(auto it:ftomini){
            if(it.second<ans[0]){
                ans[1] = ans[0];
                ans[0] = it.second;
            }else if(it.second<ans[1]){
                ans[1] = it.second;
            }
        }
        if(ans[0]==1e9||ans[1]==1e9){
            return {-1,-1};
        }
        return ans;
    }
};