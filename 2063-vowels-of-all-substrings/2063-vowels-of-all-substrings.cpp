class Solution {
public:
    long long countVowels(string word) {
        unordered_map<char,bool> vow;
        vow['a'] = vow['e'] = vow['i'] = vow['o'] = vow['u'] = 1;
        long long ans = 0;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(vow[word[i]]){
                ans += (long long)(i+1)*(n-i);
            }
        }
        return ans;
    }
};