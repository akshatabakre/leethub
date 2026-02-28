class Solution {
public:
    long long m = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long len = 0;
        long long ans = 0;
        for(int i=1;i<=n;i++){
            if((i & (i-1))==0){
                len++;
            }
            ans = (ans<<len)%m;
            ans = (ans+i)%m;
        }
        return (int)ans%m;
    }
};