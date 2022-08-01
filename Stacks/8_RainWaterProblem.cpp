#include<iostream>
using namespace std;

int RainWater(int *arr, int n){
    int *maxL = new int[n];
    int *maxR = new int[n];
    
    maxL[0]=arr[0];
    maxR[n-1]=arr[n-1];

    for(int i=1; i<n; i++){
        maxL[i] = max(maxL[i-1], arr[i]);
    }

    for(int i=n-2; i>=0; i--){
        maxR[i] = max(maxR[i+1], arr[i]);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans+=(min(maxR[i], maxL[i])-arr[i]);
    }
    return ans;
}

int main(){
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(n);
    cout<<RainWater(arr, n);
    return 0;
}