class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        for(auto i:f){
            if(i.second>1){
                return true;
            }
        }
        return false;
    }
};