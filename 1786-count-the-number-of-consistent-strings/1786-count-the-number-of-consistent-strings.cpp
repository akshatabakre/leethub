class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> allow;
        for(int i=0;i<allowed.length();i++){
            allow[allowed[i]] = 1;
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
            bool toCount = true;
            for(char ch:words[i]){
                if(allow[ch]==0){
                    toCount = false;
                    break;
                }
            }
            if(toCount){
                count++;
            }
        }
        return count;
    }
};