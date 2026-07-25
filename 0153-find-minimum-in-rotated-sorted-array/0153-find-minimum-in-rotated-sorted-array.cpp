class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[s]<=nums[mid] && nums[mid]<=nums[e]){
                return nums[s];
            }
            // if(nums[mid]<nums[s] && nums[mid]<nums[e]){
            //     return nums[mid];
            // }
            else if(nums[s]>nums[mid]){
                e = mid;
                ans = nums[mid];
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};