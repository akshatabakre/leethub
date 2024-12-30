class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        string ans = "";
        int n = word.length();
        for(int i=0;i<=numFriends;i++){
            string w = word.substr(i,n-numFriends+1);
            if(w>ans){
                ans = w;
            }
        }
        if(n>numFriends+1){
        for(int i=numFriends+1;i<n;i++){
            string w = word.substr(i);
            if(w>ans){
                ans = w;
            }
        }
        }
        return ans;
    }
};