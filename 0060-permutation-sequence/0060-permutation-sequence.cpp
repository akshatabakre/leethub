class Solution {
public:
    int fact(int n){
        int f = 1;
        for(int i=2;i<=n;i++){
            f*=i;
        }
        return f;
    }
    void solve(string&ans,vector<int>&arr,int n,int ind){
        if(arr.size()==0){
            return;
        }
        int i = ind/fact(n-1);
        ans+=char(arr[i]+'0');
        arr.erase(find(arr.begin(),arr.end(),arr[i]));
        solve(ans,arr,n-1,ind%fact(n-1));
    }
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        solve(ans,arr,n,k-1);
        return ans;
    }
};