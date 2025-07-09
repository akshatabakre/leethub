class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        int i=0;
        while(k && i<n){
            if(st.empty()){
                st.push(num[i++]);
            }else if(st.top()>num[i]){
                st.pop();
                k--;
            }else{
                st.push(num[i++]);
            }
        }
        while(k){
            st.pop();
            k--;
        }
        while(i<n){
            st.push(num[i++]);
        }
        string s = "";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        while(!s.empty() && s.back()=='0'){
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        return (s.empty())? "0":s;
    }
};