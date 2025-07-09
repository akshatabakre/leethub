class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        for(int ast:a){
            bool alive = true;
            while(alive && st.empty()==false && st.top()>0 && ast<0){
                if(abs(st.top())>abs(ast)){
                    alive = false;
                }else if(abs(ast)==abs(st.top())){
                    alive = false;
                    st.pop();
                }else{
                    st.pop();
                }
            }
            if(alive){
                st.push(ast);
            }
        }
        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};