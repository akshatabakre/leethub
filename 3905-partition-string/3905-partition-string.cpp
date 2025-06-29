class Solution {
public:
    vector<string> partitionString(string s) {
        string running = "";
        map<string,bool> mark;
        vector<string> ans;
        int n = s.length();
        for(int i=0;i<n;i++){
            running+=s[i];
            if(!mark[running]){
                ans.push_back(running);
                mark[running] = true;
                running = "";
            }
        }
        return ans;
    }
};