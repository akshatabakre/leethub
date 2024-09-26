class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        unordered_map<char,int> m;
        for(char c:s1){
            m[c] = 1;
            m[char(c+'A'-'a')] = 1;
        }
        for(char c:s2){
            m[c] = 2;
            m[char(c+'A'-'a')] = 2;
        }
        for(char c:s3){
            m[c] = 3;
            m[char(c+'A'-'a')] = 3;
        }
        vector<string> res;
        for(int i=0;i<words.size();i++){
            bool flag = true;
            for(int j=1;j<words[i].length();j++){
                if(m[words[i][j]]!=m[words[i][j-1]]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};