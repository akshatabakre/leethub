class Solution {
public:
    int setbits(int num){
        int k = 0;
        for(int i=0;i<32;i++){
            if((num & (1<<i))!=0){
                k++;
            }
        }
        return k;
    }
    int minimizeXor(int num1, int num2) {
        int n1 = setbits(num1), n2 = setbits(num2);
        //now, set bits from rightmost if k1<k2, else clear bits from leftmost bit
        if(n1==n2){
            // cout<<"s";
            return num1;
        }
        cout<<n1<<" "<<n2<<endl;
        int d = abs(n1-n2);
        if(n1<n2){
            for(int i=0;i<32 && d>0;i++){
                if((num1 & (1<<i))==0){
                // cout<<"SET at "<<i<<endl;
                // cout<<d<<endl;
                    num1 = (num1|(1<<i));
                    d--;
                }
            }
            return num1;
        }
        //clear bit
        for(int i=0;i<32 && d>0;i++){
            if((num1 & (1<<i))!=0){
                // cout<<"CLEARING at "<<i<<endl;
                // cout<<d<<endl;
                num1 = (num1 & ~(1<<i));
                d--;
            }
        }
        return num1;
    }
};