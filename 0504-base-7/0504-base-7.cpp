class Solution {
public:
    string convertToBase7(int num) {
        if(!num){
            return "0";
        }
        string rev = "";
        string ans = "";
        bool nega = false;
        if(num<0){
            nega = true;
            num*=-1;
        }
        while(num>0){
            rev+=to_string(num%7);
            num/=7;
        }
        if(nega){
            ans+='-';
        }
        for(int i=rev.length()-1;i>=0;i--){
            ans+=rev[i];
        }
        return ans;
    }
};