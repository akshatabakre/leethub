class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(),qsize=queries.size();
        vector<int> ps(n+1,0);
        unordered_map<char,bool> vowel;
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = true;
        for(int i=1;i<=n;i++){
            char s = words[i-1][0], e = words[i-1][words[i-1].length()-1];
            ps[i] = ps[i-1];
            if(vowel[s] && vowel[e]){
                ps[i]++;
            }
        }
        vector<int> answer(qsize);
        for(int i=0;i<qsize;i++){
            answer[i] = ps[queries[i][1]+1]-ps[queries[i][0]];
        }
        return answer;
    }
};