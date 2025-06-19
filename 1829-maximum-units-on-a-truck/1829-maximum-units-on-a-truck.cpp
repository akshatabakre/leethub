class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return (a[1]>b[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort according to units/box
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int boxes = 0, maxUnits = 0;
        for(int i=0;i<boxTypes.size();i++){
            int boxTaken = min(truckSize-boxes,boxTypes[i][0]);
            maxUnits += boxTaken*boxTypes[i][1];
            boxes += boxTaken;
            if(boxes == truckSize)  break;
        }
        return maxUnits;
    }
};