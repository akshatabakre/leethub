class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int i=0,j=0;
        vector<string> strings(numRows,"");
        bool forward = true;
        while(j<s.length()){
            strings[i]+=s[j];
            if(i==numRows-1){
                forward = false;
            }
            if(i==0){
                forward = true;
            }
            if(forward){
                i++;
            }else{
                i--;
            }
            j++;
        }
        string answer = "";
        for(int k=0;k<strings.size();k++){
            answer+=strings[k];
        }
        return answer;
    }
};