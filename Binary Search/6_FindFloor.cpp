#include<iostream>
using namespace std;

int Floor(int *arr, int n, int e){
    int mid, res=-1, start=0, end=n-1;

    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==e) return e;
        else if(arr[mid]<e){
            res=arr[mid];
            start=mid+1;
        }
        else end=mid-1;
    }
    return res;
}

int Ceil(int *arr, int n, int e){
    int mid, res=-1, start=0, end=n-1;

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==e) return e;
        else if(arr[mid]>e){
            res=arr[mid];
            end=mid-1;
        }
        else start=mid+1;
    }
    return res;
}

int main(){
    int arr[] = {1,2,3,4,8,9,12,15,17};
    int n = sizeof(arr)/sizeof(int);
    cout<<Floor(arr, n, 5)<<endl;
    cout<<Ceil(arr, n, 5);
    return 0;
}