class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                v.push_back(nums[i]);
            }
        }
        int maxcount = 0, currcount = 1;
        for(int i=1;i<v.size();i++){
            if(v[i] == v[i-1]+1){
                currcount++;
            }else{
                maxcount = max(currcount,maxcount);
                currcount = 1;
            }
        }
         maxcount = max(currcount,maxcount);
        return maxcount;
    }
};