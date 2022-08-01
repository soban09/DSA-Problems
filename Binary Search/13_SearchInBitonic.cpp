#include<iostream>
using namespace std;

int BS(int *arr, int e, int start, int end){
    int mid;
    while(start<=end){
        mid=(start+mid)/2;
        if(arr[mid]==e) return mid;
        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

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
    int arr[] = {1,3,8,12,4,2};
    int n = sizeof(arr)/sizeof(int);
    int idx = FindPeakEle(arr, n);
    cout<<(-1)*BS(arr, 3, 0, idx-1)*BS(arr, 3, idx, n-1);
    return 0;
}