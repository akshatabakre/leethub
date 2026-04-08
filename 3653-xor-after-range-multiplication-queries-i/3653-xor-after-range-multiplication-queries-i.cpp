class Solution {
public:
    long long mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long q = queries.size();
        long long n = nums.size();
        for(auto que:queries){
            long long l=que[0], r=que[1], k=que[2], v=que[3];
            for(long long i=l;i<=r;i+=k){
                nums[i] = (nums[i]*v)%mod;
            }
        }
        long long ans = 0;
        for(long long i:nums){
            ans = (ans^i);
        }
        return ans;
    }
};