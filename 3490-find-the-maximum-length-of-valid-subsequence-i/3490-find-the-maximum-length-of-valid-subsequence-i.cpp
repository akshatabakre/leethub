class Solution {
public:
    int solve(int ind,int parity,vector<int>& nums){
        if(ind==nums.size()){
            return 0;
        }
        if(parity){
            if(nums[ind]%2==1){
                return 1 + solve(ind+1,0,nums);
            }
            return solve(ind+1,1,nums);
        }
        return (nums[ind]%2)? solve(ind+1,0,nums) : 1+solve(ind+1,1,nums);
    }
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int e = 0;
        for(int i:nums){
            if(!(i&1)){
                e++;
            }
        }
        // cout<<e<<endl;
        return max(e,max(n-e,max(solve(0,1,nums),solve(0,0,nums))));
    }
};