class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> vowel;
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int vmax = 0, cmax = 0;
        for(int i=0;i<26;i++){
            if(vowel[char('a'+i)]){
                vmax = max(freq[i],vmax);
            }else{
                cmax = max(freq[i],cmax);
            }
        }
        return vmax+cmax;
    }
};