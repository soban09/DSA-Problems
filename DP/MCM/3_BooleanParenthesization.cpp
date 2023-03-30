#include<iostream>
using namespace std;

int BooleanParentheisation(string s, int i, int j, bool IsTrue){
    if(i>j) return 0;

    if(i==j){
        if(IsTrue) return s[i]=='T';
        else return s[i]=='F';
    }

    int ans=0;

    for(int k=i+1; k<j; k+=2){
        int lT = BooleanParentheisation(s,i,k-1, true);
        int lF = BooleanParentheisation(s,i,k-1, false);
        int rT = BooleanParentheisation(s,k+1,j, true);
        int rF = BooleanParentheisation(s,k+1,j, false);

        if(s[k]=='&'){
            if(IsTrue) ans = ans + lT*rT;
            else ans = ans + lF*rF + lF*rT + lT*rF;
        }
        else if(s[k]=='|'){
            if(IsTrue) ans = ans + lT*rT + lF*rT + lT*rF;
            else ans = ans + lF*rF;
        }
        else{
            if(IsTrue) ans = ans + lF*rT + lT*rF;
            else ans = ans + lF*rF + lT*rT;
        }
    }
    return ans;
}

int main(){
    string s = "T^F&T";
    cout<<BooleanParentheisation(s,0,s.size()-1,true);
return 0;
}