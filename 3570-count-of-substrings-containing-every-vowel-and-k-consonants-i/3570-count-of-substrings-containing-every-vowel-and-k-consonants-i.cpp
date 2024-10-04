class Solution {
public:
    bool cons(char ch){
        return ((ch!='a')&&(ch!='e')&&(ch!='i')&&(ch!='o')&&(ch!='u'));
    }
    bool allvowels(string s,int l,int r){
        if(count(s.begin()+l,s.begin()+r+1,'a')!=0 && count(s.begin()+l,s.begin()+r+1,'e')!=0 && count(s.begin()+l,s.begin()+r+1,'i')!=0 && count(s.begin()+l,s.begin()+r+1,'o')!=0 && count(s.begin()+l,s.begin()+r+1,'u')!=0){
            return true;
        }
        return false;
    }
    bool conscount(string s,int l,int r,int k){
        int count = 0;
        for(int i=l;i<=r;i++){
            if(cons(s[i])){
                count++;
            }
        }
        if(count!=k){
            return false;
        }
        return true;
    }
    int countOfSubstrings(string word, int k) {
        if(word.length()<5+k){
            return 0;
        }
        cout<<word.length()<<endl;
        int numofsubstrs = 0;
        for(int i=0;i<word.length()-k-4;i++){
            // cout<<"checking for i = "<<i<<endl;
            for(int j=i+4+k;j<word.length();j++){
                // cout<<"all vowels "<<allvowels(word,i,j)<<endl;
                if(allvowels(word,i,j)){
                    // cout<<"conscount "<<conscount(word,i,j,k)<<endl;
                    if(conscount(word,i,j,k)){
                        numofsubstrs++;
                        // cout<<"counted "<<numofsubstrs<<endl;
                    }
                }
            }
        }
        return numofsubstrs;
    }
};