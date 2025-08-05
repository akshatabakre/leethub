class Solution {
public:
    int digitsum(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i:nums){
            mp[digitsum(i)].push_back(i);
        }
        int ans = -1;
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            int n = it.second.size();
            if(n>1)
            ans = max(it.second[n-2]+it.second[n-1],ans);
        }
        return ans;
    }
};