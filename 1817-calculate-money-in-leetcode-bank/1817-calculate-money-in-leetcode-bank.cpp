class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += (i+6)/7 + (i-1)%7;
        }
        return sum;
    }
};