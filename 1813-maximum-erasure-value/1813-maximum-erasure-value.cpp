class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int l=0,r=-1;
        int n = nums.size();
        int sum = 0;
        int maxi = 0;
        while(l<n){
            while(r+1<n && mp[nums[r+1]]==0){
                r++;
                sum += nums[r];
                mp[nums[r]] = 1;
            }
            maxi = max(sum,maxi);
            mp[nums[l]]--;
            sum-=nums[l];
            l++;
            if(r<l){
                r = l-1;
            }
        }
        return maxi;
    }
};