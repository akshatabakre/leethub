class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> og(nums.size());
        og = nums;
        sort(nums.begin(),nums.end());
        int maxand = nums[nums.size()-1];
        int currlen = 0, maxlen = 0;
        for(int i=0;i<og.size();i++){
            if(og[i]==maxand){
                currlen++;
                maxlen = max(currlen,maxlen);
            } else {
                currlen = 0;
            }
        }
        return maxlen;
    }
};