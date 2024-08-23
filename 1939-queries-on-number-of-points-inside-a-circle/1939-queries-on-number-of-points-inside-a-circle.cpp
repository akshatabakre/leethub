class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<points.size();j++){
                int a = queries[i][0];
                int b = queries[i][1];
                int r = queries[i][2];
                int x = points[j][0];
                int y = points[j][1];
                if(pow(x-a,2)+pow(y-b,2)<=pow(r,2)){
                    answer[i]++;
                }
            }
        }
        return answer;
    }
};