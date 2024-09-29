class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> rm;
        for(int i=0;i<s.length();i++){
            if((m[s[i]]!=NULL && m[s[i]]!=t[i]) || (rm[t[i]]!=NULL && rm[t[i]]!=s[i])){
                return false;
            }else{
                m[s[i]] = t[i];
                rm[t[i]] = s[i];
            }
        }
        return true;
    }
};