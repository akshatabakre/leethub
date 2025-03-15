class Solution {
public:
    bool check(vector<int>& piles,int m, int h){
        long long tottime = 0;
        for(auto i:piles){
            tottime+=(i+m-1)/m;
        }
        return (tottime<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i:piles){
            maxi = max(i,maxi);
        }
        int s = 1, e = maxi, ans = 0, n = piles.size();
        while(s<=e){
            int m = s + (e-s)/2;
            if(check(piles,m,h)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};