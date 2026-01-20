class Solution {
public:
    long long appealSum(string s) {
        vector<int> lastapp(26,-1);
        int n = s.length();
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += (long long)(i-lastapp[s[i]-'a'])*(n-i);
            lastapp[s[i]-'a'] = i;
        }
        return ans;
    }

};