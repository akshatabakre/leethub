class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> scores(n);
        scores[n-1] = stoneValue[n-1];
        for(int i=n-2;i>=0;i--){
            int maxi = -1e9;
            //only i
            int x = stoneValue[i];
            if(i+1<n)   x-=scores[i+1];
            maxi = max(x,maxi);
            if(i+1<n){
                //i and i+1
                x = stoneValue[i]+stoneValue[i+1];
                if(i+2<n){
                    x-=scores[i+2];
                }
                maxi = max(x,maxi);
            }
            if(i+2<n){
                //i,i+1 and i+2
                x = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2];
                if(i+3<n){
                    x-=scores[i+3];
                }
                maxi = max(x,maxi);
            }
            scores[i] = maxi;
        }
        for(int i:scores)   cout<<i<<" ";
        if(scores[0]>0){
            return "Alice";
        }else if(scores[0]==0){
            return "Tie";
        }
        return "Bob";
    }
};