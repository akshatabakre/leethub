class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char,int> f;
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            f[s[i]]++;
            if(f.size()==(i+1)%3)   ans++;
        }
        return ans;
    }
};