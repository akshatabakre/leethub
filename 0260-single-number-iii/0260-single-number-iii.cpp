class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> c;
        for(int i=0;i<nums.size();i++){
            c[nums[i]]++;
        }
        vector<int> res;
        for(auto i:c){
            if(i.second==1){
                res.push_back(i.first);
            }
        }
        return res;
    }
};