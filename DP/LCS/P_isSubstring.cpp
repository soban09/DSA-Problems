#include<iostream>
using namespace std;

bool is_SubSeq(string x, string y){
    int j=0;
    for(int i=0; i<x.size(); i++){
        if(x[i]==y[j]) j++;
    }
    if(j==y.size()) return true;
    return false;
}

bool LCSDP(string x, string y){
    int n=x.size();
    int m=y.size();
    
    int dp[n+1][m+1];
    dp[0][0] = 0;

    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m]==m;
}

int main(){
    string x="AHGDTS";
    string y="AHS";
    if(is_SubSeq(x,y)) cout<<"True";
    else cout<<"False";
    cout<<endl;
    if(LCSDP(x,y)) cout<<"True";
    else cout<<"False";
return 0;
}