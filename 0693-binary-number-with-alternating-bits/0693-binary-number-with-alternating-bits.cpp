class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n%2;
        while(n){
            n/=2;
            if(bit==n%2){
                return false;
            }
            bit = n%2;
        }
        return true;
    }
};