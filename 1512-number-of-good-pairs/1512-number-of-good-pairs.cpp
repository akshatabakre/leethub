class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int ans = 0;
        for(auto i:count){
            int a = i.second;
            ans += a*(a-1)/2;
        }
        return ans;
    }
};