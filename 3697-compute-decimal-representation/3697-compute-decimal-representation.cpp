class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long m = 1;
        while(n){
            if(n%10){
                ans.push_back((n%10)*m);
            }
            n/=10;
            m*=10;
        }
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};