class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && words[j].find(words[i])!=string::npos && count(result.begin(),result.end(),words[i])==0){
                    result.push_back(words[i]);
                }
            }
        }
        return result;
    }
};