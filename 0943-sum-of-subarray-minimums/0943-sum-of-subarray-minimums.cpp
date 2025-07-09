#define ll long long
int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>> st;
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top().second;
            }
            st.push({arr[i],i});
        }
        while(!st.empty())  st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top().second;
            }
            st.push({arr[i],i});
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans+((ll)arr[i]*(ll)(right[i]-i)*(ll)(i-left[i])))%MOD;
        }
        return (int)ans;
    }
};