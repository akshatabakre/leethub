class Solution {
public:
    bool sameSign(int a,int b){      return ((a>0 && b>0) || (a<0 && b<0));}
    bool movAway(int a,int b){       return (a>0 && b<0);}
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            int ast = asteroids[i];
            if(st.empty()){
                st.push(ast);
                // cout<<"pushed "<<ast<<endl;
                continue;
            }else{
                // if(sameSign(ast,st.top() || movAway(ast,st.top())){
                //     st.push(ast);
                //     continue;
                // }
                bool haveToPush = true;
                while(!st.empty()){
                    if(sameSign(ast,st.top()) || movAway(ast,st.top())){
                        st.push(ast);
                        haveToPush = false; 
                        break;
                    }
                    if(abs(ast)<abs(st.top())){   
                        haveToPush = false; 
                        break;}
                    else if(abs(ast)==abs(st.top())){
                        st.pop();
                        haveToPush = false; 
                        break;
                    }
                    st.pop();
                }
                if(haveToPush){
                    st.push(ast);
                }
            }
            // if(st.empty()){
            //     cout<<"empty"<<endl;
            // }else{
            //     cout<<st.top()<<endl;
            // }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};