class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = 1e9;
        for(auto it:tasks){
            ans = min(it[0]+it[1],ans);
        }
        return ans;
    }
};