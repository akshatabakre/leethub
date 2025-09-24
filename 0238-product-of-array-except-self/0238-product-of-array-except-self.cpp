class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n),s(n);
        for(int i=0;i<n;i++){
            p[i] = nums[i];
            if(i){
                p[i]*=p[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            s[i] = nums[i];
            if(i<n-1){
                s[i]*=s[i+1];
            }
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(i>0){
                ans[i]*=p[i-1];
            }
            if(i<n-1){
                ans[i]*=s[i+1];
            }
        }
        return ans;
    }
};