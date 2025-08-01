class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        for(int i:nums){
            f[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:f){
            int fr = it.second, num = it.first;
            if(pq.size()<k){
                pq.push({fr,num});
            }else{
                if(pq.top().first < fr){
                    pq.pop();
                    pq.push({fr,num});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};