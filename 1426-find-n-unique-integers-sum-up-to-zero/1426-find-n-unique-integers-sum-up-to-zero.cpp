class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        int sum = 0;
        for(int i=1;i<n;i++){
            ans.push_back(i);
            sum+=i;
        }
        if(sum){
            ans.push_back(-sum);
        }
        return ans;
    }
};