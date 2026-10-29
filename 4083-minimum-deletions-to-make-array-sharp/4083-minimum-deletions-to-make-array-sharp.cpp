class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int d = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                d++;
            }
        }
        return n-d;
    }
};