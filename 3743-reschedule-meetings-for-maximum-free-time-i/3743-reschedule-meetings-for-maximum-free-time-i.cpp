class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0;
        int n = startTime.size();
        vector<int> pref(n);
        for(int i=0;i<n;i++){
            pref[i] = endTime[i]-startTime[i];
            if(i){
                pref[i] += pref[i-1];
            }
        }
        if(k>=n){
            return eventTime-pref[n-1];
        }
        for(int i=0;i<=n-k;i++){
            int left=0, right=eventTime;
            if(i){
                left = endTime[i-1];
            }
            if(i+k<n){
                right = startTime[i+k];
            }
            int p = 0;
            if(i) p = pref[i-1];
            ans = max(right-left-(pref[i+k-1]-p),ans);
            // cout<<duration<<endl;
        }
        return ans;
    }
};