class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int maxdays = 0;
        for(auto it:events){
            maxdays = max(it[1],maxdays);
        }
        int i = 0, ans = 0;
        for(int day=1;day<=maxdays;day++){
            while(i<events.size() && events[i][0]<=day){
                // cout<<"at day "<<day<<" adding "<<events[i][0]<<" "<<events[i][1]<<endl;
                pq.push({events[i][1],events[i][0]});
                i++;
            }
            while(!pq.empty() && day>pq.top().first){
                pq.pop();
            }
            if(!pq.empty() && day<=pq.top().first){//before the deadline of topmost task
                // cout<<"doing "<<pq.top().second<<" "<<pq.top().first<<endl;
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};