class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totsum = 0;
        for(int i:cardPoints)   totsum+=i;
        int sum = 0, minsum = 1e9;
        for(int i=0;i<n-k;i++){
            sum+=cardPoints[i];
        }
        minsum = min(sum,minsum);
        for(int i=0;i+n-k<n;i++){
            sum-=cardPoints[i];
            sum+=cardPoints[i+n-k];
            minsum = min(sum,minsum);
        }

        return totsum-minsum;
    }
};