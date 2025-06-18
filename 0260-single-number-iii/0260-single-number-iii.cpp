class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorVal = 0;
        for(int i:nums)     xorVal = (xorVal ^ i);
        long num = ((xorVal & (xorVal-1)) ^ xorVal);
        long num1 = 0, num2 = 0;
        for(int i:nums){
            if((i & num)){
                num1 = (num1 ^ i);
            }else{
                num2 = (num2 ^ i);
            }
        }
        return {(int)num1,(int)num2};
    }
};