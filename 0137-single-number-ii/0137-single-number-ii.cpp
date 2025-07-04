class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //O(n)time complexity, and O(1) space complexity
        if(nums.size()==1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i]!=nums[i-1]) && (nums[i]!=nums[i+1])){
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};