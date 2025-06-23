class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> f;
        for(int i:hand)     f[i]++;
        while(!f.empty()){
            int x = f.begin()->first;
            for(int i=x;i<x+groupSize;i++){
                if(f.count(i)){
                    f[i]--;
                    if(f[i]==0)
                        f.erase(i);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};