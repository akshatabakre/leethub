class Solution {
public:
int mod  = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        #define int long long
        hFences.push_back(1);   hFences.push_back(m);
        vFences.push_back(1);   vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        sort(hFences.begin(),hFences.end());
        m = hFences.size();
        n = vFences.size();
        unordered_map<int,bool> mp;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                mp[hFences[j]-hFences[i]] = true;
            }
        }
        int side = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++){
                if(mp[vFences[i]-vFences[j]]==true){
                    side = max((long long)vFences[i]-vFences[j],side);
                }
            }
        }
        if(side){
            return (side*side)%mod;
        }
        return -1;
        #undef int
    }
};