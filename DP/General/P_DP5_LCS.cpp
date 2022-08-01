#include<bits/stdc++.h>
using namespace std;

int LCS(string s, string t){
    //base case
    if(s.length()==0 || t.length()==0){
        return 0;
    }

    //recursie case
    if(s[0] == t[0]){
        return 1+LCS(s.substr(1), t.substr(1));
    }

    int a = LCS(s.substr(1), t);
    int b = LCS(s, t.substr(1));
    int c = LCS(s.substr(1), t.substr(1));

    return max(a, max(b,c));
}

int LCS_Better(string s, string t, int **ans){
    if(s.size()==0 || t.size()==0){
        return 0;
    }

    int m = s.size();
    int n = t.size();

    if(ans[m][n] != -1){
        return ans[m][n];
    }

    if(s[0]==t[0]){
        ans[m-1][n-1] = LCS_Better(s.substr(1), t.substr(1), ans);
        ans[m][n] = ans[m-1][n-1]+1;
    }
    
    else{
        ans[m][n-1] = LCS_Better(s, t.substr(1), ans);
        ans[m-1][n] = LCS_Better(s.substr(1), t, ans);
        ans[m][n] = max(ans[m][n-1], ans[m-1][n]);
    }
    

    return ans[m][n];
}
int LCS_Better(string s, string t){
    int m=s.size();
    int n=t.size();

    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            ans[i][j] = -1;
        }
    }
    return LCS_Better(s, t, ans);

}

int LCS_DP(string s, string t){
    int m=s.size();
    int n=t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
    }

    //edges to b filled with 0
    for(int i=0; i<=m; i++){
        ans[i][0] = 0;
    }
    for(int j=0; j<=n; j++){
        ans[0][j] = 0;
    }

    //now the empty part
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            if(s[m-i]==t[n-j]){
                ans[i][j] = 1+ans[i-1][j-1];
            }
            else{
                ans[i][j] = max(ans[i][j-1], ans[i-1][j]);
            }
        }
    }
    return ans[m][n];
}

int main(){
    string s,t;
    cin>>s>>t;

    cout<<LCS_DP(s,t)<<endl;
    cout<<LCS_Better(s,t)<<endl;
    cout<<LCS(s,t)<<endl;
    return 0;
}