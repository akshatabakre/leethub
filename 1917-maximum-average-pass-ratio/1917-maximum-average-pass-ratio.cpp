class Solution {
public:
    double diff(int x,int y){
        double a = double(x)/double(y);
        double b = double(x+1)/double(y+1);
        return b-a;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto it:classes){
            pq.push({diff(it[0],it[1]),{it[0],it[1]}});
        }
        for(int i=0;i<extraStudents;i++){
            auto top = pq.top();
            pq.pop();
            pq.push({diff(top.second.first+1,top.second.second+1),{top.second.first+1,top.second.second+1}});
        }
        double ans = 0;
        while(!pq.empty()){
            ans += (double)pq.top().second.first/(double)pq.top().second.second;
            pq.pop();
        }
        ans/=classes.size();
        return ans;
    }
};