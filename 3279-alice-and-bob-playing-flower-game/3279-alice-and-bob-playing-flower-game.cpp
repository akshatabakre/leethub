class Solution {
public:
    long long flowerGame(int n, int m) {
        #define int long long
        int e1 = n/2, e2 = m/2;
        int o1 = n - e1, o2 = m - e2;
        long long ans = 0;
        ans = (ans + (long long)(e1*o2));
        ans = (ans + (long long)(e2*o1));
        return ans;
        #undef int
    }
};