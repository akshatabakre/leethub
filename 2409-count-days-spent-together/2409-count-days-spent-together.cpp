class Solution {
public:

    int digit(char s){
        return int(s-'0');
    }
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int> daystill(12);
        daystill = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<12;i++){
            daystill[i] += daystill[i-1];
        }
        int aam = 10*digit(aa[0]) + digit(aa[1]);
        int aad = 10*digit(aa[3]) + digit(aa[4]);
        int lam = 10*digit(la[0]) + digit(la[1]);
        int lad = 10*digit(la[3]) + digit(la[4]);
        int abm = 10*digit(ab[0]) + digit(ab[1]);
        int abd = 10*digit(ab[3]) + digit(ab[4]);
        int lbm = 10*digit(lb[0]) + digit(lb[1]);
        int lbd = 10*digit(lb[3]) + digit(lb[4]);

        cout<<aad<<" "<<lbd<<endl;
        int aliceday1 = aad;
        if(aam-2>=0){
            aliceday1 += daystill[aam-2];
            // cout<<daystill[aam-2]<<endl;
        }
        int aliceday2 = lad;
        if(lam-2>=0){
            aliceday2 += daystill[lam-2];
        }

        int bobday1 = abd;
        if(abm-2>=0){
            bobday1 += daystill[abm-2];
        }
        int bobday2 = lbd;
        if(lbm-2>=0){
            bobday2 += daystill[lbm-2];
            // cout<<daystill[lbm-2]<<endl;
        }

        if(aliceday2<bobday1 || aliceday1>bobday2){
            return 0;
        }

        // cout<<min(aliceday2,bobday2)<<" "<<max(aliceday1,bobday1)<<endl;
// 
        // for(int i=0;i<12;i++){
        //     // cout<<daystill[i]<<" ";
        // }

        return min(aliceday2,bobday2) - max(aliceday1,bobday1) + 1;

    }
};