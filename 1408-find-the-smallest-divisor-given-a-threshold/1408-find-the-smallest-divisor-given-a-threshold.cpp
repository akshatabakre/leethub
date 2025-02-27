class Solution {
public:
    bool check(int d,vector<int>& nums,int& t){
        int sum = 0;
        for(int i:nums){
            sum+=(i+d-1)/d;
        }
        return (sum<=t);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = 0;
        for(auto i:nums){
            maxi = max(i,maxi);
        }
        int s = 1, e = maxi;
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(mid,nums,threshold)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};