class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        #define int long long
        map<int,int> fp,fn;
        for(int i:nums){
            fn[i]++;
        }
        int ans = 0;
        for(int i:nums){
            fn[i]--;
            ans=(ans+(fp[2*i]*fn[2*i]))%MOD;
            fp[i]++;
        }
        return ans;
        #undef int
    }
};