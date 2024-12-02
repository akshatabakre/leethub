class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string w = "";
        int wordcount = 0;
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                wordcount++;
                if(w.find(searchWord)==0){
                    return wordcount;
                }
                w="";
            }else{
                w+=sentence[i];
            }
        }
        wordcount++;
        if(w.find(searchWord)==0){
            return wordcount;
        }
        return -1;
    }
};