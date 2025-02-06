class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), pivotcount = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                pivotcount++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
        }
        for(int i=0;i<pivotcount;i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};