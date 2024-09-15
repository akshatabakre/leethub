class Solution {
public:
    bool vowel(char ch){
        return (ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }

    string reverseVowels(string s) {
        string vowels = "";
        for(int i=0;i<s.length();i++){
            if(vowel(s[i])){
                vowels+=s[i];
            }
        }
        string rvowels = "";
        for(int i=vowels.length()-1;i>=0;i--){
            rvowels+=vowels[i];
        }
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(vowel(s[i])){
                s[i] = rvowels[j++];
            }
        }
        return s;
    }
};