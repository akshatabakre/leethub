class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            map<int,int> ef, of;
            for(int j=i;j<n;j++){
                if(nums[j]%2)     of[nums[j]]++;
                else        ef[nums[j]]++;
                if(of.size()==ef.size()){
                    ans = max(j-i+1,ans);
                }
            }
        }
        return ans;
    }
};