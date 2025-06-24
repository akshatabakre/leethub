#define ll long long
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        ll minx = 1e9, maxx = 0, miny = 1e9, maxy = 0;
        ll n = coords.size();
        map<ll,set<ll>> vert,horiz;
        for(ll i=0;i<n;i++){
            vert[coords[i][0]].insert(coords[i][1]);
            horiz[coords[i][1]].insert(coords[i][0]);
            minx = min((ll)coords[i][0],minx);
            maxx = max((ll)coords[i][0],maxx);
            miny = min((ll)coords[i][1],miny);
            maxy = max((ll)coords[i][1],maxy);
        }
        ll ans = 0;
        for(auto it:vert){
            auto v = it.second;
            ll maxh = max(it.first-minx,maxx-it.first);
            ans = max(ans,maxh*(*v.rbegin()-*v.begin()));
        }
        for(auto it:horiz){
            auto h = it.second;
            ll maxh = max(it.first-miny,maxy-it.first);
            ans = max(ans,maxh*(*h.rbegin()-*h.begin()));
        }
        if(!ans)    ans=-1;
        return ans;
    }
};