class Solution {
public:
    void nqueens(int col,vector<string>& board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&lowerdiag,vector<int>&upperdiag){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++){
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[board.size()-1+col-row]==0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiag[row+col] = 1;
                upperdiag[board.size()-1+col-row] = 1;
                nqueens(col+1,board,ans,leftrow,lowerdiag,upperdiag);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdiag[row+col] = 0;
                upperdiag[board.size()-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        vector<vector<string>> ans;
        vector<int> leftrow(n,0),lowerdiag(2*n-1,0),upperdiag(2*n-1,0);
        nqueens(0,board,ans,leftrow,lowerdiag,upperdiag);
        return ans;
    }
};