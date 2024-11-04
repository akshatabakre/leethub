class Solution {
public:
    string compressedString(string word) {
        int c = 1;
        string res = "";
        char prev = word[0];
        for(int i=1;i<word.length();i++){
            if(word[i]==prev){
                if(c==9){
                    res+=to_string(c);
                    res+=word[i];
                    c=0;
                }
                c++;
            }else{
                res+=to_string(c);
                res+=prev;
                c=1;
            }
            prev = word[i];
        }
        res+=to_string(c);
        res+=prev;
        return res;
    }
};