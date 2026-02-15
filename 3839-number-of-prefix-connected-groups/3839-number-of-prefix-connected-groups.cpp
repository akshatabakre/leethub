class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,vector<string>> mp;
        int n = words.size();
        for(int i=0;i<n;i++){
            if(words[i].length()<k){
                continue;
            }
            mp[words[i].substr(0,k)].push_back(words[i]);
        }
        int ans = 0;
        for(auto it:mp){
            if(it.second.size()>=2){
                ans++;
            }
        }
        return ans;
    }
};