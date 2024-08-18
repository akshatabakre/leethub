class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> count(50,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]-1]++;
        }
        int x = 0;
        for(int i=0;i<count.size();i++){
            if(count[i]==2){
                x = x^(i+1);
            }
        }
        return x;
    }
};