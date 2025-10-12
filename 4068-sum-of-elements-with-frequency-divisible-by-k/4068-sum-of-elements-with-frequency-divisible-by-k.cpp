class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int> f;
        for(int i:nums){
            f[i]++;
        }
        int ans = 0;
        for(auto it:f){
            if(it.second%k==0){
                ans+=(it.first*it.second);
            }
        }
        return ans;
    }
};