class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for(char ch:s){
            ans = max((26-(ch-'a'))%26,ans);
        }
        return ans;
    }
};