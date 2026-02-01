class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;
        if(n==0){
            return ans;
        }
        ans += log2(n);
        if((n & (n+1)) == 0){
            ans++;
        }
        return ans;
    }
};