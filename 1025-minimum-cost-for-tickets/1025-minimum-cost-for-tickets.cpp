class Solution {
public:
    int f(int ind,vector<int>& d, vector<int>& c){
        if(ind>=d.size()){
            return 0;
        }
        if(ind==d.size()-1){
            return min(c[0],min(c[1],c[2]));
        }
        int nId = d.size();
        while(d[nId-1]>d[ind]+29){
            nId--;
        }
        int pass30 = c[2] + f(nId,d,c);
        while(d[nId-1]>d[ind]+6){
            nId--;
        }
        int pass7 = c[1] + f(nId,d,c);
        int pass1 = c[0] + f(ind+1,d,c);
        return min(pass1,min(pass7,pass30));
    }
    int mincostTickets(vector<int>& d, vector<int>& c) {
        return f(0,d,c);
    }
};