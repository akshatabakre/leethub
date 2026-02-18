class Solution {
public:
    int setbits(int x){
        int ans = 0;
        while(x){
            ans += x%2;
            x/=2;
        }
        return ans;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> bit(n,0);
        for(int i=0;i<n;i++){
            bit[i] = (bit[i]|(1<<(s[i]-'a')));
        }
        for(int i=1;i<n;i++){
            bit[i] = (bit[i]^bit[i-1]);
        }
        vector<bool> res;
        for(auto it:queries){
            int l = it[0], r = it[1], k = it[2];
            int xxor = bit[r];
            if(l-1>=0){
                xxor = (xxor^bit[l-1]);
            }
            res.push_back(setbits(xxor)/2<=k);
        }
        return res;
    }
};