class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xv = 0;
        for(int i:nums)     xv = (xv^i);
        return xv;
    }
};