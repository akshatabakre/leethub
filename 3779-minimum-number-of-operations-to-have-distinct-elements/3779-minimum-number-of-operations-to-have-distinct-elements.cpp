class Solution {
public:
    int minOperations(vector<int>& nums) {
        //solved using gpt
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            if(mp.count(nums[i])){
                return (1+(i/3));
            }
            mp[nums[i]]=1;
        }
        return 0;
    }
};