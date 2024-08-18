class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> fs;
        unordered_map<char,int> ft;
        for(int i=0;i<s.length();i++){
            fs[s[i]]++;
            ft[t[i]]++;
        }
        int steps = 0;
        for(auto i:fs){
            if(fs[i.first]>ft[i.first]){
                steps+=(fs[i.first]-ft[i.first]);
            }
        }
        return steps;
    }
};