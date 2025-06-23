class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        set<int> ms(hand.begin(),hand.end());
        map<int,int> f;
        for(int i:hand)     f[i]++;
        while(!ms.empty()){
            int x = *(ms.begin());
            f[x]--;
            if(f[x]==0){
                ms.erase(x);
            }
            for(int i=x+1;i<x+groupSize;i++){
                if(ms.count(i)){
                    f[i]--;
                    if(f[i]==0)
                        ms.erase(i);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};