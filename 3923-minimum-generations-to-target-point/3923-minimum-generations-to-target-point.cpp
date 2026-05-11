class Solution {
public:
   
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        set<vector<int>> s;
        
        for(auto &i : points){
            if(i == target){
                return 0;
            }
            s.insert(i);
        }

        bool flag = true;
        int cnt = 0;

        while(flag){

            cnt++;
            flag = false;

            vector<vector<int>> cur(s.begin(), s.end());
            int n = cur.size();

            vector<vector<int>> naya;

            for(int i = 0; i < n; i++){

                for(int j = i + 1; j < n; j++){

                    int x = (cur[i][0] + cur[j][0]) / 2;
                    int y = (cur[i][1] + cur[j][1]) / 2;
                    int z = (cur[i][2] + cur[j][2]) / 2;

                    vector<int> v = {x, y, z};

                    if(v == target){
                        return cnt;
                    }

                    if(s.find(v) == s.end()){
                        naya.push_back(v);
                        flag = true;
                    }
                }
            }

            for(auto &i : naya){
                s.insert(i);
            }
        }
        
        return -1;
    }
};