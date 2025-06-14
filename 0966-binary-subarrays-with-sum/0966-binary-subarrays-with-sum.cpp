class Solution {
public:
    int countAtMost(int goal,vector<int>& nums){
        int head = 0, tail = 0;
        int ans = 0;
        int n = nums.size();
        int sum = nums[tail];
        while(tail<n){
            while(head+1<n && sum+nums[head+1]<=goal){
                head++;
                sum+=nums[head];
            }
            if(sum<=goal)   ans+=(head-tail+1);
            sum-=nums[tail];
            tail++;
            if(tail>head){
                head = tail;
                sum = nums[tail];
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(goal,nums) - countAtMost(goal-1,nums);
    }
};