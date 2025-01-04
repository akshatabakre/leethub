class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                return -1;
            }
        }
        sort(nums.begin(),nums.end());
        int ind=0;
        while(ind<n && nums[ind]==k){
            ind++;
        }
        if(ind==n){
            return 0;
        }
        ind++;
        int ans = 1;
        for(ind;ind<n;ind++){
            if(nums[ind]!=nums[ind-1]){
                ans++;
            }
        }
        return ans;
    }
};