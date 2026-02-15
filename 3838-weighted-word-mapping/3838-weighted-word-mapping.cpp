class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        int n = words.size();
        for(int i=0;i<n;i++){
            int x = 0;
            for(char ch:words[i]){
                x += weights[ch-'a'];
            }
            x = x%26;
            res+=char(26-x-1+'a');
        }
        return res;
    }
};