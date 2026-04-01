class Solution {
public:
    bool special(string&s){
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[0]){
                return false;
            }
        }
        return true;
    }
    int maximumLength(string s) {
        int n = s.length();

        for(int len=n-2;len>=1;len--){
            for(int i=0;i+len<=n;i++){
                string word = s.substr(i,len);
                if(!special(word))  continue;
                int cnt = 0;
                for(int j=i+1;j+len<=n;j++){
                    string w = s.substr(j,len);
                    if(w==word){
                        cnt++;
                    }
                }
                if(cnt>=2){
                    return len;
                }
            }
        }
        return -1;
    }
};
//aabbb
//aabbaaa