class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = n*n, evensum = n*(n+1);
        return gcd(oddsum,evensum);
    }
};