class Solution {
public:
    int myAtoi(string s) {
        #define int long long
        int i=0;
        int n = s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        int num = 0;
        bool pos = true;
        if(i<n && s[i]=='-'){
            pos = false;
            i++;
        }else if(i<n && s[i]=='+'){
            i++;
        }
        while(i<n && s[i]=='0'){
            i++;
        }
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')){
                    if(pos)
                    return INT_MAX;
                    else
                    return INT_MIN;
                }
                num = (num*10);
                num += (s[i]-'0');
                i++;
            }else{
                break;
            }
        }
        if(!pos)    num*=-1;
        return num;
        #undef int
    }
};