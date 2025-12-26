class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> p(n);
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                p[i]++;
            }
        }
        for(int i=1;i<n;i++){
            p[i]+=p[i-1];
        }
        int ind = 0;
        int minp = p[n-1];

        for(int i=1;i<=n;i++){
            if(minp>i+p[n-1]-(2*p[i-1])){
                ind = i;
                minp = i+p[n-1]-(2*p[i-1]);
            }
        }
        return ind;
    }
};