class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> freq;
        map<char,int> timer;
        int curr=0;
        for(auto i:tasks){
            freq[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:freq){
            timer[i.first]=1;
            pq.push({timer[i.first],i.second});
        }
        while(!pq.empty()){
            // curr++;
            int t=pq.top().first;
            if(curr<t)
                curr = t;
            else
                curr++;
            int fr=pq.top().second;
            if(t<=curr){
                pq.pop();
                if(fr-1>0)
                pq.push({t+n+1,fr-1});
            }
        }
        return curr;
        

        
    }
};