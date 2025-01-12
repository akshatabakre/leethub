class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if((s[0]==')' && locked[0]==1)||(s[n-1]=='(' && locked[n-1]==1) || n%2==1){
            return false;
        }
        // int var = 0, zeroes = 0;
        // for(char ch:s){
        //     var += (ch=='(')? (1) : (-1);
        // }
        // for(char ch:locked){
        //     zeroes += (ch=='1')? 0 : 1;
        // }
        // for(int i=0;i<n;i++){
        //     if(locked[i]=='1'){
        //         cout<<i<<" ";
        //     }
        // }
        int adj = 0,var=0;
        bool finish = true;
        for(int i=0;i<n;i++){
            if(locked[i]=='1' && s[i]=='('){
                var++;
            }
            if(locked[i]=='0'){
                adj++;
            }
            if(locked[i]=='1' && s[i]==')'){
                if(var>0){
                    var--;
                }else{
                    if(adj>0){
                        adj--;
                    }else{
                        finish = false;
                        break;
                    }
                }
            }
        }
        var = 0, adj = 0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='1' && s[i]==')'){
                var++;
            }
            if(locked[i]=='0'){
                adj++;
            }
            if(locked[i]=='1' && s[i]=='('){
                if(var>0){
                    var--;
                }else{
                    if(adj>0){
                        adj--;
                    }else{
                        finish = false;
                        break;
                    }
                }
            }
        }
        if(finish){
            return true;
        }
        return false;
        // if(zeroes<var)  return false;
        // return true;
    }
};