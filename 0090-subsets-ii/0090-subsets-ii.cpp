class Solution {
public:
    void subset(vector<int>& nums,vector<vector<int>>& ans,vector<int>&v, int ind){
        ans.push_back(v);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            v.push_back(nums[i]);
            subset(nums,ans,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        subset(nums,ans,v,0);
        return ans;
    }
};