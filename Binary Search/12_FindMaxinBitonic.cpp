#include<iostream>
using namespace std;

int FindPeakEle(int *arr, int n){
    int mid, start=0, end=n-1;
        
    if(n==1) return 0;
        
    if(n==2){
        if(arr[0]>arr[1]) return 0;
        else return 1;
    }
        
    while(start<=end){
        mid=start+(end-start)/2;
        int prv = (mid+n-1)%n;
        int nxt = (mid+1)%n;
            
        if(arr[mid]>arr[prv] && arr[mid]>arr[nxt]) return mid;
        else if(arr[prv]>arr[mid]) end=mid-1;
        else start=mid+1;
    }
    return 0;
}

int main(){
    int arr[] = {1,2,1,3,6,5,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<FindPeakEle(arr, n);
    return 0;
}