class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evens = 0;
        for(int i:nums){
            if((i&1)==0){
                evens++;
            }
        }
        return (evens>1);
    }
};