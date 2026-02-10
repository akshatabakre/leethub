class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            set<int> e,o;

            for(int j=i;j<n;j++){
                if(nums[j]%2){
                    o.insert(nums[j]);
                }else{
                    e.insert(nums[j]);
                }
                if(o.size()==e.size()){
                    ans = max(j-i+1,ans);
                }
            }
        }
        return ans;
    }
};