#include<iostream>
#include<cmath>
using namespace std;

int NoOfBST(int h){
    if(h<=1){
        return 1;
    }

    int x = NoOfBST(h-1);
    int y = NoOfBST(h-2);

    int mod = pow(10, 9)+7;
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(2*((long)(x)*y)%mod);

    int ans = (temp1+temp2)%mod;
    return ans;
}

int NoOfBST_betterHelper(int h, int *ans){
    if(h<=1){
        ans[h]=1;
        return ans[h];
    }

    if(ans[h-1]==0){
        ans[h-1]=NoOfBST_betterHelper(h-1, ans);
    }
    int x = ans[h-1];

    if(ans[h-2]==0){
        ans[h-2]=NoOfBST_betterHelper(h-2, ans);
    }
    int y = ans[h-2];

    int mod = pow(10, 9)+7;
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(2*((long)(x)*y)%mod);

    int z = (temp1+temp2)%mod;
    ans[h]=z;
    return z;
}

int NoOfBST_better(int h){
    int *ans = new int[h+1];
    for(int i=0; i<=h; i++){
        ans[i]=0;
    }
    return NoOfBST_betterHelper(h, ans);
}

int NoOfBST_DP(int h){
    int *ans = new int[h+1];
    for(int i=0; i<=h; i++){
        ans[i]=0;
    }
    ans[0]=1;
    ans[1]=1;
    ans[2]=3;
    ans[3]=15;
    int mod = pow(10, 9)+7;

    for(int i=4; i<=h; i++){
        int x =ans[i-1];
        int y =ans[i-2];
        
        int temp1 = (int)(((long)(x)*x)%mod);
        int temp2 = (int)(2*((long)(x)*y)%mod);

        ans[i] = (temp1+temp2)%mod;
    }

    return ans[h];
}


int main(){
    int h;
    cin>>h;

    cout<<NoOfBST(h)<<endl;
    cout<<NoOfBST_better(h)<<endl;
    cout<<NoOfBST_DP(h)<<endl;
return 0;
}