#include<iostream>
#include<algorithm>
using namespace std;

string printLPS(string x, string y, int n, int m){
    int dp[n+1][m+1];

    dp[0][0]=0;
    for(int i=1; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 0;
        }
    }
    
    int ei=0, ej=0, mx=-1;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(dp[i][j]>mx){
                mx=dp[i][j];
                ei=i;ej=j;
            }
        }
    }

    int i=ei, j=ej;
    string s = "";

    while(dp[i][j]>0){
        s.push_back(x[i-1]);
        i--;j--;
    }
    
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    // string x = "agbcba";
    string x = "aacabdkacaa";
    string y = x;
    reverse(y.begin(), y.end());

    cout<<printLPS(x,y,x.size(),y.size());
    return 0;
}