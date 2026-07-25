class Solution {
public:
    int maxProduct(int n) {
        int l = 0, sl = 0;
        while(n){
            int d = n%10;
            n/=10;
            if(d>l){
                sl = l;
                l = d;
            }else if(d>sl){
                sl = d;
            }
        }
        return (l*sl);
    }
};