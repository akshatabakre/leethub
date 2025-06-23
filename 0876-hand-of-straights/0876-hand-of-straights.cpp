class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> hm;
        for(int i:hand){
            hm[i]++;
        }
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i:hand){
            minheap.push(i);
        }
        while(!minheap.empty()){
            while(!minheap.empty() && hm[minheap.top()]==0){
                minheap.pop();
            }
            if(!minheap.empty()){
                int x = minheap.top();
                for(int i=x;i<x+groupSize;i++){
                    if(hm[i]==0){
                        return false;
                    }
                    hm[i]--;
                }
            }
        }
        return true;
    }
};