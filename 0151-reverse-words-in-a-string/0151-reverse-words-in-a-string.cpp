class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        for(char ch:s){
            if(ch==' '){
                if(word.size()){
                    st.push(word);
                }
                word = "";
            }else{
                word+=ch;
            }
        }
        if(word.size()){
            st.push(word);
        }
        string ans = "";
        while(!st.empty()){
            string w = st.top();
            st.pop();
            ans += w;
            if(!st.empty()){
                ans += " ";
            }
        }
        return ans;
    }
};