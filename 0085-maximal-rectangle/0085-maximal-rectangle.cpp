class Solution {
public:
    void calculateS(vector<pair<int,int>>& small,vector<int>& height){
        int n = height.size();
        stack<pair<int,int>> st;
        //pushing prev elements
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=height[i]){
                st.pop();
            }
            if(st.empty()){
                small[i].first = -1;
            }else{
                small[i].first = st.top().second;
            }
            st.push({height[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        //pushing next elements
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=height[i]){
                st.pop();
            }
            if(st.empty()){
                small[i].second = n;
            }else{
                small[i].second = st.top().second;
            }
            st.push({height[i],i});
        }
        return;
    }
    int maxarea(vector<int>& height){
        int n = height.size();
        int maxA = 0;
        //calculate PSE and NSE
        vector<pair<int,int>> smaller(n);
        calculateS(smaller,height);
        for(int i=0;i<n;i++){
            int prev = smaller[i].first, next = smaller[i].second;
            // cout<<prev<<" "<<next<<endl;
            maxA = max(maxA,height[i]*(next-prev-1));
            // cout<<height[i]<<endl;
        }
        // cout<<maxA<<endl;
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols,0);
        // for(int i=0;i<cols;i++) dp[i] = matrix[0][i];
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    // cout<<matrix[i][j]<<endl;
                    dp[j]++;
                }else{
                    dp[j] = 0;
                }
            }
            cout<<dp[0]<<endl;
            ans = max(ans,maxarea(dp));
        }
        return ans;
    }
};