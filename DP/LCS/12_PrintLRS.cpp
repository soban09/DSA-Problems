//a derivative of LCS

#include<iostream>
#include<algorithm>
using namespace std;

string LRS(string x, int n){
    int dp[n+1][n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(i!=j and x[i-1]==x[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i=n,j=n;
    string ans="";

    while(i>0 && j>0){
        if(dp[i][j]==dp[i-1][j-1]+1){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string x = "axxzxy";
    cout<<LRS(x,x.size());
return 0;
}