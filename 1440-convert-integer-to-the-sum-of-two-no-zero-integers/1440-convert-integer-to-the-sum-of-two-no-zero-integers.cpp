class Solution {
public:
    bool nozero(int n){
        while(n){
            if(n%10==0){
                return false;
            }
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n/2;i++){
            if(nozero(i) && nozero(n-i)){
                return {i,n-i};
            }
        }
        return {1,n-1};
    }
};