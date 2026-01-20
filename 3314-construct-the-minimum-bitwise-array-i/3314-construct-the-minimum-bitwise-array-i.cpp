class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int a = -1;
            int nm = nums[i];
            for(int j=1;j<nm;j++){
                if(nm==(j|(j+1))){
                    a = j;
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};