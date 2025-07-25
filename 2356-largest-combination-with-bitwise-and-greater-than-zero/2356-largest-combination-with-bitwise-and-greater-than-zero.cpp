class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitfreq(32,0);
        for(int i=0;i<candidates.size();i++){
            for(int j=0;j<32;j++){
                if(((candidates[i]>>j) & 1)==1){
                    bitfreq[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            ans = max(bitfreq[i],ans);
        }
        return ans;
    }
};