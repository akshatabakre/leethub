class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sumofdiv = 1;
        if(num==1){
            return false;
        }
        for(int i=2;i<sqrt(num);i++){
            if(num%i==0){
                cout<<i<<" is divisor"<<endl;
                sumofdiv+=i;
                sumofdiv+=(num/i);
                cout<<sumofdiv<<endl;
                if(sumofdiv>num){
                    return false;
                }
            }
        }
        cout<<sumofdiv<<endl;
        if(num==sumofdiv){
            return true;
        }
        return false;
    }
};