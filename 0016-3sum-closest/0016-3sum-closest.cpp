class Solution {
public:
    int threeSumClosest(vector<int>& nums, int x) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[n-1];
        for(int j=1;j<n-1;j++){
            int i=0,k=n-1;
            while(i<j && j<k){
                int s = nums[i]+nums[j]+nums[k];
                if(abs(s-x)==abs(ans-x)){
                    ans = max(s,ans);
                }else if(abs(s-x)<abs(ans-x)){
                    ans = s;
                }
                if(s==x)    return s;
                if(s<x){
                    i++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};