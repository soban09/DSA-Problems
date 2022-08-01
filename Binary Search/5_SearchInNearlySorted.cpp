#include<iostream>
using namespace std;

int BS(int *arr, int n, int e){
    int start=0, end=n-1, mid;

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==e) return mid;

        if(mid-1>=start && arr[mid-1]==e) return mid-1;

        if(mid+1<=end && arr[mid+1]==e) return mid+1;

        else if(arr[mid]>=e) end=mid-2;

        else start=mid+2;
    }
    return -1;
}


int main(){
    int arr[] = {5,10,30,20,40};
    int n = sizeof(arr)/sizeof(int);
    cout<<BS(arr,n,20);
    return 0;
}