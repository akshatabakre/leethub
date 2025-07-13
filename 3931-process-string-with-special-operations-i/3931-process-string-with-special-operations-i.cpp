class Solution {
public:
    bool isChar(char ch){
        return (ch>='a' && ch<='z');
    }
    string processStr(string s) {
        int n = s.length();
        string res = "";
        for(int i=0;i<n;i++){
            if(isChar(s[i])){
                cout<<1<<endl;
                res += s[i];
            }else if(s[i]=='*'){
                if(res.length())
                res.pop_back();
            }else if(s[i]=='#'){
                res = res + res;
            }else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};