class Solution {
public:
    bool check(long long num,long long k){
        #define int long long
        long long b = 0;
        for(int i=0;i<64;i++){
            if(num & (1LL<<i)){
                b++;
            }
        }
        return k>=b;
        #undef int
    }
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = 1LL*num1;
        if(n1<=num2){
            return -1;
        }
        for(int k=1;k<=64;k++){
            n1-=num2;
            if(n1<0){
                break;
            }
            if(check(n1,1LL*k) && n1>=k){
                return k;
            }
        }
        return -1;
    }
};