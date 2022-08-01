#include<iostream>
using namespace std;

int BS(int *arr, int start, int end, int e){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==e) return mid;
        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

pair<int,int> FindIndex(int *arr, int e){
    pair<int, int> pr;
    int start=0, end=1;

    while(arr[end]<e){
        start=end;
        end*=2;
    }

    pr.first=start;
    pr.second=end;
    return pr;
}

int main(){
    int arr[] = {3,5,8,11,13,16,20,24,27,31,36,41,45,46};
    pair<int, int> pr = FindIndex(arr, 16);
    cout<<BS(arr, pr.first, pr.second, 16);
    return 0;
}