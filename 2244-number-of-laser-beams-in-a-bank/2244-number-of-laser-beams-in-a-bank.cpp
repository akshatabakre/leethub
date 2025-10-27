class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int d = 0;
            for(char ch:bank[i]){
                d += (ch=='1');
            }
            if(d){
                ans += prev*d;
                prev = d;
            }
        }
        return ans;
    }
};