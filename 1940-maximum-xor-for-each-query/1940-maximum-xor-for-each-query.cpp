class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xortillnow = 0, xorneeded = pow(2,maximumBit)-1;
        vector<int> answer(nums.size());
        for(int i=0;i<nums.size();i++){
            xortillnow = xortillnow ^ nums[i];
            answer[i] = xortillnow ^ xorneeded;
        }
        for(int i=0;i<answer.size()/2;i++){
            swap(answer[i],answer[answer.size()-i-1]);
        }
        return answer;
    }
};