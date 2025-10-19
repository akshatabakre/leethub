class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> rtof(value,0);//rem,freq
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int rem = -1;
            if(nums[i]>0){
                rem = nums[i]%value;
            }else{
                rem = (value + (nums[i]%value))%value;
            }
            nums[i] = (rtof[rem]*value)+rem;
            rtof[rem]++;
        }
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i:nums){
            if(i==ans){
                ans++;
            }else{
                break;
            }
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        return ans;
    }
};