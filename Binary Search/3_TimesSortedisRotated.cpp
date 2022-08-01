#include<iostream>
using namespace std;

// if 'left-rotated' -> return 'mid'
// else if 'right-rotated' -> return 'n-mid'

int Occurence(int *arr, int n){
    // already sorted
    if(arr[0]<arr[n-1]) return 0;

    int mid, start=0, end=n-1;

    while(start<=end){
        mid = (start+end)/2;
        int nxt = (mid+1)%n;
        int prv = (mid+n-1)%n;

        if(arr[mid]<=arr[prv] && arr[mid]<=arr[nxt]){
            return mid;
        }
        else if(arr[start]<=arr[mid]){
            start=mid+1;
        }
        else end=mid-1;
    }
    return 0;
}

int main(){
    int arr[] = {15,18,2,5,6,7,11,12};
    int n = sizeof(arr)/sizeof(int);
    cout<<Occurence(arr,n);
    return 0;
}