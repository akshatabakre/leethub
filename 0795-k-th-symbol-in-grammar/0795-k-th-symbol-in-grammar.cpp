class Solution {
public:
    int kthGrammar(int n, int k) {
        int len = (1<<(n-1));
        int K = k;
        char curr = '0';
        while(len!=1){
            if(curr=='0'){
                if(K<=(len/2)){
                    len/=2;
                }else{
                    curr = '1';
                    K-=(len/2);
                    len/=2;
                }
            }else{
                if(K<=(len/2)){
                    len/=2;
                }else{
                    curr = '0';
                    K-=(len/2);
                    len/=2;
                }
            }
        }
        return int(curr-'0');
    }
};