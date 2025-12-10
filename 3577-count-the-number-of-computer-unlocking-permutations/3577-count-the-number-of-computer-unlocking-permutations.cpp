class Solution {
public:
int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        #define int long long
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
        }
        int ans = 1;
        for(int i=2;i<n;i++){
            ans = (ans*i)%MOD;
        }
        return ans;
        #undef int
    }
};