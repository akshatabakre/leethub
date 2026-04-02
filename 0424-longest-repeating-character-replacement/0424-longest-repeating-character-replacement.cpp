class Solution {
public:

    bool check(map<char,int>&mp,char ch,int k,int l,int r){
        mp[ch]++;
        int f = 0;
        for(auto it:mp){
            f = max(it.second,f);
        }
        int flips = r-l+1 - f;
        mp[ch]--;
        return (flips<=k);
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0;
        int r=-1;
        int ans = 0;
        map<char,int> mp;
        while(l<n){
            while(r+1<n && check(mp,s[r+1],k,l,r+1)){
                r++;
                mp[s[r]]++;
            }
            ans = max(r-l+1,ans);
            if(l>r){
                l++;
                r=l-1;
            }else{
                mp[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};