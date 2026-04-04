class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize){
            return false;
        }
        multiset<int> ms(hand.begin(),hand.end());
        while(!ms.empty()){
            int x = *ms.begin();
            for(int i=0;i<groupSize;i++){
                if(ms.find(x+i)==ms.end()){
                    return false;
                }
                ms.erase(ms.find(x+i));
            }
        }
        return true;
    }
};