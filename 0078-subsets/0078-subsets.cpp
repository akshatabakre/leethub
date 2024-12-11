class Solution {
public:
    void solve(vector<int>& nums,int ind,vector<int>&v,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        //do not pick the indth index
        solve(nums,ind+1,v,ans);
        //pick the indth index
        v.push_back(nums[ind]);
        solve(nums,ind+1,v,ans);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,0,v,ans);
        return ans;
    }
};