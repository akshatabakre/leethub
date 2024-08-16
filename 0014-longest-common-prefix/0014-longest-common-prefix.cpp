class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        if(strs.size()>1){
            for(int i=1;i<strs.size();i++){
                string a = "";
                int p = 0;
                for(int j=0;j<strs[i].length();j++){
                    if(strs[i][j]==prefix[p++]){
                        a+=strs[i][j];
                    } else {
                        break;
                    }
                }
                prefix = a;
            }
        }
        return prefix;
    }
};