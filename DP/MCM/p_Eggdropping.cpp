#include<bits/stdc++.h>
#include<climits>
using namespace std;

int dp[10][10];

int EggDropping(int e, int f){
    if(f==0 || f==1) return f;
    if(e<=1) return f;

    int mn = INT_MAX;

    for(int k=1; k<=f; k++){
        int tmp = 1 + max(EggDropping(e-1,k-1), EggDropping(e,f-k));

        mn = min(mn, tmp);
    }
    return mn;
}

int EggDroppingMem(int e, int f){
    if(f==0 || f==1) return f;
    if(e<=1) return f;

    if(dp[e][f]!=-1) return dp[e][f];

    int mn = INT_MAX;

    for(int k=1; k<=f; k++){
        if(dp[e-1][k-1]==-1){
            dp[e-1][k-1] = EggDropping(e-1, k-1);
        }
        if(dp[e][f-k]==-1){
            dp[e][f-k] = EggDropping(e, f-k);
        }

        int tmp = 1+max(dp[e-1][k-1], dp[e][f-k]);

        mn = min(mn, tmp);
    }
    dp[e][f] = mn;
    return mn;
}

int main(){
    int e,f;
    cin>>e>>f;
    memset(dp, -1, sizeof(dp));

    cout<<EggDropping(e,f)<<endl;
    cout<<EggDroppingMem(e,f)<<endl;
return 0;
}