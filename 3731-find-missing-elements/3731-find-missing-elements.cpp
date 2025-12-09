class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        map<int,int> f;
        int mini = 1e9, maxi = -1e9;
        for(int i:nums)
        {
            mini = min(i,mini);
            maxi = max(i,maxi);
            f[i]=1;
        }
        for(int i=mini;i<=maxi;i++){
            if(!f[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};