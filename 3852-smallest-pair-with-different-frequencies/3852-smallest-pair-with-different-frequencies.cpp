class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> f;
        int mini = 1e9;
        for(int i:nums){
            mini = min(i,mini);
            f[i]++;
        }
        int ans = 1e9;
        for(int i:nums){
            if(f[i]!=f[mini]){
                ans = min(i,ans);
            }
        }
        if(ans==1e9){
            return {-1,-1};
        }
        return {mini,ans};
    }
};