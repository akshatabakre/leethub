class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        vector<bool> filled(baskets.size(),false);
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(!filled[j] && baskets[j]>=fruits[i]){
                    filled[j] = true;
                    break;
                }
            }
        }
        for(int i=0;i<baskets.size();i++){
            if(!filled[i]){
                unplaced++;
            }
        }
        return unplaced;
    }
};