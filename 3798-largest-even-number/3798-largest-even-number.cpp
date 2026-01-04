class Solution {
public:
    string largestEven(string s) {
        string x = "";
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.length() && s[i]=='1'){
            i++;
        }
        while(i<s.length()){
            x+=s[i];
            i++;
        }
        reverse(x.begin(),x.end());
        return x;
    }
};