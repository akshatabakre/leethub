class Solution {
public:
    long long coloredCells(int n) {
        long long diff = 0;
        long long ans = 1;
        while(n--){
            ans+=diff;
            diff+=4;
        }
        return ans;
    }
};