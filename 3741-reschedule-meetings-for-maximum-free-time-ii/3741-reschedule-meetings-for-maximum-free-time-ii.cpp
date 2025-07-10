class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> free, events;
        int n = startTime.size();
        int prev = 0;
        for(int i=0;i<n;i++){
            free.push_back(startTime[i]-prev);
            events.push_back(endTime[i]-startTime[i]);
            prev = endTime[i];
        }
        free.push_back(eventTime-prev);
        vector<int> pmax(n+1,0), smax(n+1,0);
        for(int i=0;i<n;i++){
            pmax[i] = free[i];
            if(i)   pmax[i] = max(pmax[i-1],pmax[i]);
        }
        for(int i=n;i>=0;i--){
            smax[i] = free[i];
            if(i<n){
                smax[i] = max(smax[i+1],smax[i]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            bool altExists = false;
            if(ans>=free[i]+free[i+1]+events[i]){
                continue;
            }
            if(((i)?pmax[i-1]>=events[i]:false) || ((i+2<n+1)? smax[i+2]>=events[i] : false)){
                altExists = true;
            }
            if(altExists){
                ans = max(free[i]+free[i+1]+events[i],ans);
            }else{
                ans = max(free[i]+free[i+1],ans);
            }
        }
        return ans;
    }
};