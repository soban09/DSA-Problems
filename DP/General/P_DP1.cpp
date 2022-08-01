#include <bits/stdc++.h>
using namespace std;

int MinSteps(int n){
    if(n==1){
        return 0;
    }
    
    int x, y=INT_MAX, z=INT_MAX;
    x = MinSteps(n-1);
    if(n%2==0){
        y=MinSteps(n/2);
    }
    if(n%3==0){
        z=MinSteps(n/3);
    }
    
    return min(x, min(y,z))+1;
}

int MinStepsBetter(int n, int *ans){
    if(n==1){
        ans[1]=0;
        return 0;
    }
    
    int y=INT_MAX, z=INT_MAX;
    
    if(ans[n-1]==-1){
        ans[n-1]=MinStepsBetter(n-1, ans);
    }
    
    if(n%2==0){
        if(ans[n/2]==-1){
            ans[n/2]=MinStepsBetter(n/2, ans);
        }
        y=ans[n/2];
    }
    if(n%3==0){
        if(ans[n/3]==-1){
            ans[n/3]=MinStepsBetter(n/3, ans);
        }
        z=ans[n/3];
    }
    
    ans[n]=min(ans[n-1], min(y,z))+1;
    return ans[n];
}

int MinStepsBetterHelper(int n){
    int *ans = new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i]=-1;
    }
    return MinStepsBetter(n, ans);
}

int MinSteps_DP(int n){
    int *ans = new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i]=-1;
    }
    ans[0]=100;
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    ans[4]=2;
    
    int x, y=INT_MAX, z=INT_MAX;
    
    for(int i=5; i<=n; i++){
        if(i%2==0){
            y=ans[i/2];
        }
        if(i%3==0){
            z=ans[i/3];
        }
        x=ans[i-1];
        
        ans[i]=min(x, min(y,z))+1;
        
        y=INT_MAX;
        z=INT_MAX;
    }
    
    int a = ans[n];
    delete [] ans;
    return a;
}

int main() {
	
	int n;
	cin>>n;
	
	cout<<MinSteps(n)<<endl;
	cout<<MinStepsBetterHelper(n)<<endl;
	cout<<MinSteps_DP(n)<<endl;
	
	return 0;
}
