class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> m;
        for(int i=0;i<names.size();i++){
            m[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            names[i] = m[heights[heights.size()-i-1]];
        }
        return names;
    }
};