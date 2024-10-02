class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(k>=s.length()){
            string f = "";
            for(int i=0;i<s.length();i++){
                f+=s[i];
            }
            for(int i=0;i<s.length();i++){
                f+=(char((s[i]+1)%('z'+1)));
            }
            s = f;
        }
        cout<<s<<endl;
        return s[k-1];
    }
};