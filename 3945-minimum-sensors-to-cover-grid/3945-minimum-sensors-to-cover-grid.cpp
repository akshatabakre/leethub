class Solution {
public:
    int minSensors(int n, int m, int k) {
        int side = 2*k + 1;
        int N = (n+side-1)/side;
        N*=side;
        int M = (m+side-1)/side;
        M*=side;
        int ans = (N*M + side*side -1)/(side*side);
        return ans;
    }
};