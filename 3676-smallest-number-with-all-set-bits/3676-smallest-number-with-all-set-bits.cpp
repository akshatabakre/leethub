class Solution {
public:
    int smallestNumber(int n) {
        int x = log2(n);
        return (1<<(x+1))-1;
    }
};