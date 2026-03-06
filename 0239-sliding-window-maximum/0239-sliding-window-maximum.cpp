class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        res.push_back(mp.rbegin()->first);
        for(int i=0;i+k<n;i++){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            mp[nums[i+k]]++;
            res.push_back(mp.rbegin()->first);
        }
        return res;
    }
};