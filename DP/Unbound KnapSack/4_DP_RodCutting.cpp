//Ditto same as Unbounded KnapSack

#include<iostream>
using namespace std;

int RodCuttung(int *price, int *len, int L){
    int dp[L+1][L+1];

    for(int i=0; i<=L; i++) dp[i][0] = 0;
    for(int i=0; i<=L; i++) dp[0][i] = 0;

    for(int i=1; i<=L; i++){
        for(int j=1; j<=L; j++){
            if(len[i-1]<=j){
                dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[L][L];
}

int main(){
    int len[] = {1,2,3,4};
    int price[] = {5,6,8,8};

    cout<<RodCuttung(price,len,4);
return 0;
}