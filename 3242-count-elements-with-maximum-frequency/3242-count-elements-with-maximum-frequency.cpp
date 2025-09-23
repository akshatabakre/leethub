class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> numtofreq;
        map<int,int> freqtonum;
        for(int i:nums){
            numtofreq[i]++;
        }
        int maxfreq = 0;
        for(auto it:numtofreq){
            freqtonum[it.second]+=it.second;
            maxfreq = max(maxfreq,it.second);
        }
        return freqtonum[maxfreq];
    }
};