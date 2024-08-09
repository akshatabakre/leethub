class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = x;
        int dsum = 0;
        while(n>0){
            dsum += (n%10);
            n/=10;
        }
        if(x%dsum==0){
            return dsum;
        } else {
            return -1;
        }
    }
};