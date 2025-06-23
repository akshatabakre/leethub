class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        for(int i=0;i<n;i+=k){
            string sub = s.substr(i,k);
            if(sub.length()<k){
                while(sub.length()<k){
                    sub+=fill;
                }
            }
            ans.push_back(sub);
        }
    return ans;
    }
};