class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        for(int i=0;i<queries.size();i++){
            if(queries[0]==queries[1]){
                answer[i] = 0;
            }else{
                int a = 0;
                for(int j=queries[i][0];j<=queries[i][1];j++){
                    a = a^arr[j];
                }
                answer[i] = a;
            }
        }
        return answer;
    }
};