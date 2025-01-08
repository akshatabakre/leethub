class Solution {
public:
    bool comp(string a,string b){
        return a.length()<=b.length();
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].length()==words[j].length()){
                    if(words[i]==words[j]){
                        count++;
                    }
                }else{
                    if(words[j].substr(0,words[i].length())==words[i] && words[j].substr(words[j].length()-words[i].length())==words[i]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};