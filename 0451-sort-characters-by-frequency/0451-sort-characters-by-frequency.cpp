class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> f;
        for(char ch:s){
            f[ch]++;
        }
        map<int,string> mp;
        for(auto i:f){
            mp[i.second]+=i.first;
        }

        string ans = "";
        for(auto it:mp){
            string w =it.second;
            for(char ch:w){
                int t = f[ch];
                while(t--){
                    ans.push_back(ch);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};