class Solution {
public:
    bool isAlphabet(char ch){
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
    }
    bool isDigit(char ch){
        return (ch>='0' && ch<='9');
    }
    bool isValid(string word) {
        vector<char> vowels, consonants;
        map<char,int> vow;
        vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
        vow['A'] = vow['E'] = vow['I'] = vow['O'] = vow['U'] = 1;
        for(char  ch:word){
            if(isAlphabet(ch)){
                if(vow[ch]){
                    vowels.push_back(ch);
                }else{
                    consonants.push_back(ch);
                }
            }else if(!isDigit(ch)){
                return false;
            }
        }
        return (!vowels.empty() && !consonants.empty() && word.length()>=3);
    }
};