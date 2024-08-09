class Solution {
public:
    int commonFactors(int a, int b){
        int less,more;
        if(a<b){
            less = a;
            more = b;
        } else {
            less = b;
            more = a;
        }
        int commonfactors = 0;
        for(int i=1;i<=less;i++){
            if(a%i==0 && b%i==0){
                commonfactors++;
            }
        }
        return commonfactors;
    }
};