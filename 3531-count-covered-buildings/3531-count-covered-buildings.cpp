class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<set<int>> row(n+1), col(n+1);
        for(auto it:buildings){
            row[it[0]].insert(it[1]);
            col[it[1]].insert(it[0]);
        }
        int cnt = 0;
        for(auto it:buildings){
            if(*(row[it[0]].begin())<it[1] && *(row[it[0]].rbegin())>it[1] && *(col[it[1]].begin())<it[0] && *(col[it[1]].rbegin())>it[0]){
                cnt++;
            }
        }
        return cnt;
    }
};