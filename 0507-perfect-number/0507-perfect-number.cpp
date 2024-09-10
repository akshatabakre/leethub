class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sumofdiv = 0;
        for(int i=1;i<num;i++){
            if(num%i==0){
                cout<<i<<" is divisor"<<endl;
                sumofdiv+=i;
                cout<<sumofdiv<<endl;
            }
        }
        cout<<sumofdiv<<endl;
        if(num==sumofdiv){
            return true;
        }
        return false;
    }
};