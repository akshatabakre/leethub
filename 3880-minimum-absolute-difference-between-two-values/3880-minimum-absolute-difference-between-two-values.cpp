class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int mindiff = 1e9;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                for(int j=0;j<n;j++){
                    if(nums[j]==2){
                        mindiff = min(abs(i-j),mindiff);
                    }
                }
            }
        }
        if(mindiff==1e9){
            return -1;
        }
        return mindiff;
    }
};