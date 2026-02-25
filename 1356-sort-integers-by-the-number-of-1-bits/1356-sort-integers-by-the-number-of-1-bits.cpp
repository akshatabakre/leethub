class Solution {
public:
    int sb(int n){
        int x;
        while(n){
            x+=n%2;
            n/=2;
        }
        return x;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<vector<int>> v(arr.size(),vector<int>(2));
        for(int i=0;i<arr.size();i++){
            v[i] = {sb(arr[i]),arr[i]};
        }
        sort(v.begin(),v.end());
        for(auto it:v){
            ans.push_back(it[1]);
        }
        return ans;
    }
};