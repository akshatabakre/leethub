class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            bool countword = true;
            for(int j=0;j<words[i].length();j++){
                if(count(allowed.begin(),allowed.end(),words[i][j])==0){
                    countword=false;
                    break;
                }
            }
            if(countword){
                ans++;
            }
        }
        return ans;
    }
};