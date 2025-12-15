class Solution {
public:
    string reverseWords(string s) {
        map<char,bool> vowel;
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = true;
        string ans = "";
        int f = 0;
        int i=0;
        int n = s.length();
        while(i<n && s[i]!=' '){
            ans+=s[i];
            if(vowel[s[i]]){
                f++;
            }
            i++;
        }
        string word = "";
        int p = 0;
        while(i<n){
            if(s[i]==' '){
                if(p==f){
                    reverse(word.begin(),word.end());
                }
                ans += word;
                // cout<<word<<" "<<p<<endl;
                ans += ' ';
                word = "";
                p=0;
            }else{
                word += s[i];
                if(vowel[s[i]]){
                    p++;
                }
            }
            i++;
        }
        if(p==f){
            reverse(word.begin(),word.end());
        }
        ans += word;
        return ans;
    }
};