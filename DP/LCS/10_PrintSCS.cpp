//a derivative of Print LCS + SCS
//hard

#include<bits/stdc++.h>
using namespace std;

string PrintLCS(string x, string y, int n, int m){
    int dp[n+1][m+1];
    dp[0][0] = 0;

    for(int i=1; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i=n, j=m;
    //string indexing ends at n-1 and m-1 but i and j are initialized to n and m
    //hence we use i-1 and j-1 in x and y

    string s = "";
    while(i>0 and j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                //moving in i
                s.push_back(x[i-1]);
                i--;
            }
            else{
                //moving in j
                s.push_back(y[j-1]);
                j--;
            }
        }
    }

    //now the leftover strings 
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }

    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }  

    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";
    
    cout<<PrintLCS(x, y, x.size(), y.size());
return 0;
}