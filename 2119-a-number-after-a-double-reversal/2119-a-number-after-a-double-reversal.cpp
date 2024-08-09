class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0){
            return true;
        } else {
            string n = to_string(num);
            if(n[n.length()-1]=='0'){
                return false;
            } else {
                return true;
            }
        }
    }
};