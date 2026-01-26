class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> v;
        int mindiff = 1e9;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<mindiff){
                v.clear();
                v.push_back({arr[i-1],arr[i]});
                mindiff = arr[i]-arr[i-1];
            }else if(arr[i]-arr[i-1]==mindiff){
                v.push_back({arr[i-1],arr[i]});
            }
        }
        return v;
    }
};