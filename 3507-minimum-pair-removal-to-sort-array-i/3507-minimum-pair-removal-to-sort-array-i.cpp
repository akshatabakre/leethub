class Solution {
public:
    bool inc(vector<int>&nums){
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!inc(nums)){
            ans++;
            int ind = -1;
            int minsum = 1e9;
            int n = nums.size();
            for(int i=0;i+1<n;i++){
                if(minsum>nums[i]+nums[i+1]){
                    minsum = nums[i]+nums[i+1];
                    ind = i;
                }
            }
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                if(i==ind){
                    v.push_back(nums[i]+nums[i+1]);
                    i++;
                }else{
                    v.push_back(nums[i]);
                }
            }
            nums = v;
        }
        return ans;
    }
};