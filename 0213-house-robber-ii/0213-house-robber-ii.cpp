class Solution {
public:
    int solve(vector<int>& nums){
        int prev = nums[0], prev2 = 0, curr = 0;
        for(int i=1;i<nums.size();i++){
            int pick = nums[i],notpick = 0;
            if(i>1){
                pick += prev2;
            }
            notpick += prev;
            curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        vector<int> v1, v2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                v2.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                v1.push_back(nums[i]);
            }
        }
        for(int i=0;i<v1.size();i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        cout<<solve(v1)<<" "<<solve(v2)<<endl;
        return max(solve(v1),solve(v2));
    }
};