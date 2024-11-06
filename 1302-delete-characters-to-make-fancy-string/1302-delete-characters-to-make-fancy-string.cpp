class Solution {
public:
    string makeFancyString(string s) {
        string output = "";
        int count = 1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                if(count>=2){
                    output+=s[i-1];
                    output+=s[i-1];
                }else{
                    output+=s[i-1];
                }
                count=1;
            }
        }
        if(count>=2){
            output+=s[s.length()-1];
            output+=s[s.length()-1];
        }else{
            output+=s[s.length()-1];
        }
        return output;
    }
};