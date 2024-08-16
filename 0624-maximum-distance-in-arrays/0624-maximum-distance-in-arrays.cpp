class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1 = INT_MIN, maxind1;
        for(int i=0;i<arrays.size();i++){
            if(max1<arrays[i][arrays[i].size()-1]){
                max1 = arrays[i][arrays[i].size()-1];
                maxind1 = i;
            }
        }
        int maxdist = 0;
        for(int i=0;i<arrays.size();i++){
            if(maxind1!=i){
                if(maxdist<max1-(arrays[i][0])){
                    maxdist = max1-(arrays[i][0]);
                }
            }
        }
        int min = INT_MAX, minind;
        for(int i=0;i<arrays.size();i++){
            if(min>arrays[i][0]){
                min = arrays[i][0];
                minind = i;
            }
        }
        int md = 0;
        for(int i=0;i<arrays.size();i++){
            if(minind!=i){
                if(md<arrays[i][arrays[i].size()-1]-min){
                    md = arrays[i][arrays[i].size()-1]-min;
                }
            }
        }
        return max(md,maxdist);
    }
};