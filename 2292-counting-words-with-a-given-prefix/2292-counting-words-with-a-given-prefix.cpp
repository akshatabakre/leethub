class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, n = words.size(), m = pref.length();
        for(int i=0;i<n;i++){
            if(words[i].substr(0,m)==pref){
                count++;
            }
        }
        return count;
    }
};