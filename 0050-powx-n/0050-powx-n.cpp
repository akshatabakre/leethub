class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if(power<0){
            power*=-1;
            x = (1.0/x);
        }
        double ans = 1.0;
        while(power){
            if(power&1){
                ans*=x;
                power--;
            }else{
                x*=x;
                power/=2;
            }
        }
        return ans;
    }
};