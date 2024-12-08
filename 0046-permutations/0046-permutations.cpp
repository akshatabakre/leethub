class Solution {
public:
    // void perm(vector<vector<int>>& ans, vector<int>& v,vector<int>& nums,vector<bool>& picked){
    //     if(v.size()==nums.size()){
    //         ans.push_back(v);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(picked[i]==false){
    //             picked[i] = true;
    //             v.push_back(nums[i]);
    //             perm(ans,v,nums,picked);
    //             v.pop_back();
    //             picked[i] = false;
    //         }
    //     }
    // }
    void perm2(int ind,vector<int>& nums,vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            perm2(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> v;
        // vector<bool> picked(nums.size(),false);
        // perm(ans,v,nums,picked);
        perm2(0,nums,ans);
        return ans;
    }
};