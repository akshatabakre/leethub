class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorv = 0;
        for(int i=0;i<derived.size();i++){
            xorv ^= derived[i];
        }
        if(xorv){
            return false;
        }
        return true;
    }
};