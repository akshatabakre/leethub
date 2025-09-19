class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) {
        v.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int num = stoi(cell.substr(1));
        v[num][cell[0]-'A'] = value;
    }
    
    void resetCell(string cell) {
        int num = stoi(cell.substr(1));
        v[num][cell[0]-'A'] = 0;
    }
    
    int getValue(string formula) {
        int ans = 0;
        int plus = formula.find('+');
        string one = formula.substr(1,plus-1);
        string two = formula.substr(plus+1);
        if(one[0]<='Z' && one[0]>='A'){
            ans += v[stoi(one.substr(1))][one[0]-'A'];
        }else{
            ans += stoi(one);
        }
        if(two[0]>='A' && two[0]<='Z'){
            ans += v[stoi(two.substr(1))][two[0]-'A'];
        }else{
            ans += stoi(two);
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */