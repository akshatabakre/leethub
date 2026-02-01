class Solution {
public:
    bool check(int k,vector<int>&nums){
        long long x = 0;
        for(int i:nums){
            x += (i/k);
            if(i%k)
                x++;
        }
        return (x<=(long long)k*k);
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i:nums) ans=max(ans,i);
        int s=1,e=max(ans,n);
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(mid,nums)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};