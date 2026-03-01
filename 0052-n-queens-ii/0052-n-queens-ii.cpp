class Solution {
public:
    int n;
    int ans;
    vector<int> queens;

    bool check(int row,int col){
        for(int pr=0;pr<row;pr++){
            int pc = queens[pr];
            if(pc==col || abs(row-pr)==abs(col-pc)){
                return 0;
            }
        }
        return 1;
    }
    void rec(int level){
        if(level==n){
            ans++;
            return;
        }
        for(int ch=0;ch<n;ch++){
            if(check(level,ch)){
                queens.push_back(ch);
                rec(level+1);
                queens.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        this->n = n;
        ans = 0;
        rec(0);
        return ans;
    }
};