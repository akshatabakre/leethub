class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b = arr;
        sort(b.begin(),b.end());
        unordered_map<int,int> rank;
        int r = 1;
        for(int i=0;i<b.size();i++){
            if(rank[b[i]] == 0){
            rank[b[i]] = r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};