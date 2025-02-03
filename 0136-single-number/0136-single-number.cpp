class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> countnum;
        for(int i=0;i<nums.size();i++){
            countnum[nums[i]]=0;
        }
        for(int i=0;i<nums.size();i++){
            countnum[nums[i]]++;
        }
        for(auto i:countnum){
            if(i.second==1){
                return i.first;
            }
        }
        return -1;
    }
};