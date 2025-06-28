class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> ans,mark(n);
        for(int i=n-1;i>n-k-1;i--){
            mark[v[i].second] = 1;
        }
        for(int i=0;i<n;i++){
            if(mark[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};