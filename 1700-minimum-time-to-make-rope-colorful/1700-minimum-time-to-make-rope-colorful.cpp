class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        int sum = neededTime[0];
        priority_queue<int> pq;
        pq.push(neededTime[0]);
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                sum+=neededTime[i];
                pq.push(neededTime[i]);
            }else{
                ans += (sum-pq.top());
                while(!pq.empty()){
                    pq.pop();
                }
                sum = neededTime[i];
                pq.push(neededTime[i]);
            }
        }
        ans += (sum-pq.top());
        return ans;
    }
};