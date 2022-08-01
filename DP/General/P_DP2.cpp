#include<bits/stdc++.h>
using namespace std;

int SumSquare(int n){
    if(n==0 ||n==1 || n==2 || n==3){
        return n;
    }
    int MinCount=INT_MAX;
    int currentCount=0;

    for(int i=1; i*i<n; i++){
        currentCount = SumSquare(n-i*i);
        if(MinCount > currentCount){
            MinCount = currentCount;
        }
    }
    return MinCount+1;
}

int SumSquareBetterHelper(int n, int *ans){
    if(n==1){
        ans[1]=1;
        return 1;
    }
    
    int MinCount=INT_MAX;
    int currentCount=1;
    
    for(int i=1; i*i<n; i++){
        if(ans[n-i*i]==-1){
            ans[n-i*i] = SumSquareBetterHelper(n-i*i, ans);
        }
        currentCount = ans[n-i*i];
        if(MinCount > currentCount){
            MinCount = currentCount;
        }
    }
    
    ans[n] = MinCount+1;
    return ans[n];
}

int SumSquareBetter(int n){
    int *ans = new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i]=-1;
    }    
    return SumSquareBetterHelper(n, ans);
}

int SumSquareDP(int n){
    int *DP = new int[n+1];
    for(int i=0; i<=n; i++){
        DP[i]=INT_MAX;
    }

    DP[0]=0;
    DP[1]=1;
    DP[2]=2;
    DP[3]=3;

    for(int i=1; i*i<=n; i++){
        for(int j=0; i*i+j<=n; j++){
            DP[i*i+j] = min(DP[i*i+j], 1+DP[j]);
        }
    }
    int ans = DP[n];
    delete [] DP;
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<SumSquare(n)<<endl;
    cout<<SumSquareBetter(n)<<endl;
    cout<<SumSquareDP(n)<<endl;
return 0;
}