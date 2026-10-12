class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int a = -1, b = -1;
        int maxpr = -1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || nums[i]==nums[j])    continue;
                if(nums[i]+nums[j]==target){
                    if(nums[i]*nums[j]>maxpr){
                        maxpr = nums[i]*nums[j];
                        if(nums[i]>nums[j]){
                            a = i;
                            b = j;
                        }else{
                            a = j;
                            b = i;
                        }
                    }
                }
            }
        }

        return {a,b};
    }
};