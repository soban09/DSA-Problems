#include<iostream>
using namespace std;

int MaxSumInSubArr(int *arr, int n, int k){
    int i=0,j=0,sum=0,mx=0;
    while(j<n){
        sum += arr[j];
        if(j-i+1 < k) j++;

        else if(j-i+1 == k){
            mx = max(mx, sum);
            sum-=arr[i];
            i++;j++;
        }
    }
    return mx;
}

int main(){
    int arr[] = {2,5,1,8,2,9,1};
    cout<<MaxSumInSubArr(arr,7,3);
    return 0;
}