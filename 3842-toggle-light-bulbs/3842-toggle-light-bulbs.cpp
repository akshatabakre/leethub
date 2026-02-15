class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> state(100,0);
        int n = bulbs.size();
        for(int i=0;i<n;i++){
            state[bulbs[i]-1] = !state[bulbs[i]-1];
        }
        vector<int> res;
        for(int i=0;i<100;i++){
            if(state[i]){
                res.push_back(i+1);
            }
        }
        return res;
    }
};