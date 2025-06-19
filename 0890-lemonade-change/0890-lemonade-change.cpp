class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5)     five++;
            else if(bills[i]==10){
                if(five==0)     return false;
                five--;
                ten++;
            }else{
                if(ten==0){
                    if(five<3)      return false;
                    five-=3;
                }else{
                    if(five){
                        ten--;
                        five--;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};