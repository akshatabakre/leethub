class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;
        for(int i=0;i<words.size();i++){
            if(count(words[i].begin(),words[i].end(),x)!=0){
                indices.push_back(i);
            }
        }
        return indices;
    }
};