class Solution {
public:
    int timeToMinConverter(string t){
        string min = t.substr(3,2);
        int m = stoi(min);
        string hour = t.substr(0,2);
        int h = stoi(hour);
        int minutes = m + (h*60);
        return minutes;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> m(timePoints.size());
        for(int i=0;i<timePoints.size();i++){
            m[i] = timeToMinConverter(timePoints[i]);
        }
        int minminutes = INT_MAX;
        sort(m.begin(),m.end());
        int minimum_minutes = INT_MAX;
        int currmin = INT_MAX;
        int additional = 24*60;
        for(int i=0;i<m.size()-1;i++){
            currmin = min(m[i+1]-m[i],additional+m[i]-m[i+1]);
            minimum_minutes = min(minimum_minutes,currmin);
        }
        currmin = min(m[m.size()-1]-m[0],additional+m[0]-m[m.size()-1]);
        minimum_minutes = min(minimum_minutes,currmin);
        return minimum_minutes;
    }
};