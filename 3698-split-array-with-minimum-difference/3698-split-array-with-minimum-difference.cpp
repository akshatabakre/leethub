class Solution {
public:
    long long splitArray(vector<int>& nums) {
        #define int long long
        int n = nums.size();
        vector<bool> inc(n),dec(n);
        inc[0] = true;
        int i=1;
        while(i<n && nums[i]>nums[i-1]){
            inc[i] = true;
            i++;
        }
        while(i<n){
            inc[i] = false;
            i++;
        }
        dec[n-1]=true;
        i=n-2;
        while(i>=0 && nums[i]>nums[i+1]){
            dec[i]=true;
            i--;
        }
        while(i>=0){
            dec[i] = false;
            i--;
        }
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }
        int ans = 1e12;
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1]){
                ans = min(abs(pref[n-1]-2*pref[i]),ans);
            }
        }
        if(ans==1e12){
            return -1;
        }
        return ans;
        #undef int
    }
};