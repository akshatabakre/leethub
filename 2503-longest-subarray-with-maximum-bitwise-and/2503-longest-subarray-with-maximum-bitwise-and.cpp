class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxand = 0;
        for(int i=0;i<nums.size();i++){
            maxand = max(nums[i],maxand);
        }
        int currlen = 0, maxlen = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxand){
                currlen++;
                maxlen = max(currlen,maxlen);
            } else {
                currlen = 0;
            }
        }
        return maxlen;
    }
};