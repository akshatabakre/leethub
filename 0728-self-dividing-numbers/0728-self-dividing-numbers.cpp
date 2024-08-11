class Solution {
public:
    bool isSelfDividing(int n){
        vector<int> digits;
        int m = n;
        while(m>0){
            if(m%10==0){
                return false;
            } else {
                digits.push_back(m%10);
            }
            m/=10;
        }
        bool yorn = true;
        for(int i=0;i<digits.size();i++){
            if(n%digits[i]!=0){
                yorn = false;
            }
        }
        return yorn;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};