class Solution {
public:
    string reverseByType(string s) {
        string lc="",sp="";
        for(char ch:s){
            if(ch>='a' && ch<='z')  lc+=ch;
            else                    sp+=ch;
        }
        reverse(lc.begin(),lc.end());
        reverse(sp.begin(),sp.end());
        int a=0,b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                s[i] = lc[a];
                a++;
            }else{
                s[i] = sp[b];
                b++;
            }
        }
        return s;
    }
};