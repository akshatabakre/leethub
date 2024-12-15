class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        unordered_map<int,int> m;//<time,ind>
        int prev = 0;
        for(int i=0;i<events.size();i++){
            if(m[events[i][1]-prev]==0 || m[events[i][1]-prev]>events[i][0])
                m[events[i][1]-prev] = events[i][0];
            prev = events[i][1];
        }
        int maxt = 0, corr_i = 0;
        for(auto i:m){
            if(i.first>maxt){
                corr_i = i.second;
                maxt = i.first;
            }
        }
        return corr_i;
    }
};