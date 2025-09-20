class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            avg+=nums[i];
        }
        avg/=(n);
        sort(nums.begin(),nums.end());
        int ans = max(1,avg+1);
        for(int i:nums){
            if(ans==i){
                ans++;
            }
        }
        return ans;
    }
};