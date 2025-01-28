class Solution {
public:
    int numRabbits(vector<int>& a) {
        map<int,int> m;
        int n = a.size();
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        int ans = 0;
        for(auto i:m){
            int x = (i.second+i.first)/(i.first+1);
            ans+=(x*(i.first+1));
        }
        return ans;
    }
};