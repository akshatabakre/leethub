class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int totaltime = 0;
        for(int i=0;i<garbage.size();i++){
            totaltime += garbage[i].length();
        }
        for(int i=1;i<travel.size();i++){
            travel[i] += travel[i-1];
        }
        int m=-1,p=-1,g=-1;
        for(int i=0;i<garbage.size();i++){
            if(count(garbage[i].begin(),garbage[i].end(),'M')!=0){
                m = i;
            }
            if(count(garbage[i].begin(),garbage[i].end(),'P')!=0){
                p = i;
            }
            if(count(garbage[i].begin(),garbage[i].end(),'G')!=0){
                g = i;
            }
        }
        if(m>0){
            totaltime += travel[m-1];
        }
        if(p>0){
            totaltime += travel[p-1];
        }
        if(g>0){
            totaltime += travel[g-1];
        }
        return totaltime;
    }
};