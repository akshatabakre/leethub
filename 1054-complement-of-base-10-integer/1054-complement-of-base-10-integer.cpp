class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int r = 2;
        int num = 0;
        int N = n;
        while(n>0){
            num++;
            n/=2;
        }
        return pow(r,num)-N-1;
    }
};