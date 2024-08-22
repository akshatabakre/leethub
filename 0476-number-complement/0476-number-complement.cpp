class Solution {
public:
    int findComplement(int num) {
        int r = 2;
        int n = 0;
        int N = num;
        while(num>0){
            n++;
            num/=2;
        }
        return pow(r,n)-N-1;
    }
};