class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> s;
        for(int i=1;i<=n;i++){
            s.push_back(to_string(i));
        }
        sort(s.begin(),s.end());
        vector<int> v(s.size());
        for(int i=0;i<s.size();i++){
            v[i] = stoi(s[i]);
        }
        return v;
    }
};