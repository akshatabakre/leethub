class Solution {
public:
    vector<int> findKMP(string s){
        int n = s.length();
        int i=0,j=-1;
        vector<int> kmp(n+1);
        kmp[0] = -1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j = kmp[j];
            }
            i++;
            j++;
            kmp[i] = j;
        }
        return kmp;
    }
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> kmp;
        kmp = findKMP(s);
        return s.substr(0,kmp[n]);
    }
};