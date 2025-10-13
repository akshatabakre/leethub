class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        string prev = "";
        vector<string> ans;
        for(int i=0;i<n;i++){
            string s = words[i];
            sort(s.begin(),s.end());
            if(s==prev){
                prev = s;
                continue;
            }
            ans.push_back(words[i]);
            prev = s;
        }
        return ans;
    }
};