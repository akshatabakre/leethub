class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        vector<int> res;
        for(auto i:f){
            if(i.second>(nums.size()/3)){
                res.push_back(i.first);
            }
        }
        return res;
    }
};