class Solution {
public:
    string removeChars(string s,int & score,string ref,int x){
        stack<char> st;
        for(char ch:s){
            if(!st.empty() && st.top()==ref[0] && ch==ref[1]){
                    st.pop();
                    score += x;
                    continue;
            } 
            st.push(ch);
        }
        string t = "";
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
    int maximumGain(string s, int x, int y) {
        int score = 0;
        if(x>y){
            string t = removeChars(s,score,"ab",x);
            string temp = removeChars(t,score,"ba",y);
        }else{
            string t = removeChars(s,score,"ba",y);
            string temp = removeChars(t,score,"ab",x);
        }
        return score;
    }
};