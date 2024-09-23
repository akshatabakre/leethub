class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs2(strs.size());
        for(int i=0;i<strs.size();i++){
            strs2[i] = strs[i];
        }
        for(int i=0;i<strs2.size();i++){
            sort(strs2[i].begin(),strs2[i].end());
        }
        unordered_map<string,vector<int>> m;
        for(int i=0;i<strs2.size();i++){
            m[strs2[i]].push_back(i);
        }
        vector<vector<string>> answer;
        for(auto i:m){
            vector<string> a;
            for(int j=0;j<m[i.first].size();j++){
                a.push_back(strs[m[i.first][j]]);
            }
            answer.push_back(a);
        }
        return answer;
    }
};