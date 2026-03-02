class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans = "";
        int j=0;
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = j;
                ans+=s[i];
                j++;
            }else{
                if(j-mp[s[i]]>k){
                    mp[s[i]] = j;
                    ans+=s[i];
                    j++;
                }
            }
        }
        return ans;
    }
};