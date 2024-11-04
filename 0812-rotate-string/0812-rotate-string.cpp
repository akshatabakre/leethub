class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()<s.length()){
            return false;
        }
        vector<string> options;
        for(int i=0;i<s.length();i++){
            string word = "";
            for(int j=i;word.size()<goal.size();j=(j+1)%s.length()){
                word+=s[j];
            }
            options.push_back(word);
        }
        if(count(options.begin(),options.end(),goal)>0){
            return true;
        }
        return false;
    }
};