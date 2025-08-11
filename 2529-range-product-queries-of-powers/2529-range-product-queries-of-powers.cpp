class Solution {
public:
    int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
                exp--;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        #define ll long long
        vector<ll> powers;
        for(int i=0;i<32;i++){
            if((n&(1<<i))){
                powers.push_back(i);
            }
        }
        ll m = powers.size();
        vector<ll> pref(m);
        for(int i=0;i<m;i++){
            pref[i] = powers[i];
            if(i){
                pref[i]+=pref[i-1];
            }
        }
        ll q = queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            ll l = queries[i][0], r = queries[i][1];
            ll x = pref[r];
            if(l){
                x-=pref[l-1];
            }
            ans[i] = power(2,x);
        }
        return ans;
        #undef ll
    }
};