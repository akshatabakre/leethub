class Solution {
public:
    bool vowel(char c){
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')  return true;
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')  return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowels;
        string t = s;
        for(int i=0;i<s.length();i++){
            if(vowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int index = 0;
        for(int i=0;i<t.length();i++){
            if(vowel(t[i]) && index<vowels.size()){
                t[i] = vowels[index++];
            }
        }
        return t;
    }
};