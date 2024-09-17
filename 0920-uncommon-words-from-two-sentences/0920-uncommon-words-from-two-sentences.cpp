class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> f;
        string currstr = "";
        for(char ch:s1){
            if(ch==' '){
                f[currstr]++;
                currstr = "";
            }else{
                currstr+=ch;
            }
        }
        f[currstr]++;
        currstr="";
        for(char ch:s2){
            if(ch==' '){
                f[currstr]++;
                currstr = "";
            }else{
                currstr+=ch;
            }
        }
        f[currstr]++;
        vector<string> uncommon;
        for(auto i:f){
            if(f[i.first]==1){
                uncommon.push_back(i.first);
            }
        }
        return uncommon;
    }
};