class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        int index = 0;
        while(n[index]!='6' && index<n.length()){
            index++;
        }
        if(index!=n.length()){
            num += 3*pow(10,n.length()-index-1);
        }
        return num;
    }
};