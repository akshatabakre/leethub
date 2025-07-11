class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        #define int long long
        sort(meetings.begin(),meetings.end());
        vector<int> availAt(n,0);
        int m = meetings.size();
        vector<int> ans(n,0);
        for(int i=0;i<m;i++){
            bool found = false;
            for(int j=0;j<n;j++){
                if(meetings[i][0]>=availAt[j]){
                    found = true;
                    availAt[j] = meetings[i][1];
                    ans[j]++;
                    break;
                }
            }
            if(!found){
                int minT = LLONG_MAX, room = -1;
                for(int j=0;j<n;j++){
                    if(minT>availAt[j]){
                        minT = availAt[j];
                        room = j;
                    }
                }
                ans[room]++;
                availAt[room] = (availAt[room] + meetings[i][1]-meetings[i][0]);
            }
        }
        int room = -1, maxM = 0;
        for(int i=0;i<n;i++){
            if(maxM<ans[i]){
                room = i;
                maxM = ans[i];
            }
        }
        return room;
        #undef int
    }
};