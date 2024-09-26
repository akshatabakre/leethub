class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        if(maxi==nums.size()-1){
            return maxi+1;
        }else{
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=i){
                    return i;
                }
            }
        }
        return 0;
    }
};