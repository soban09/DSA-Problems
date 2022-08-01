#include<iostream>
using namespace std;

int BS(int *arr, int start, int end, int e){
    int mid, res=-1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==e){
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return res;
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
    int arr[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
    pair<int, int> pr = FindIndex(arr, 1);
    cout<<BS(arr, pr.first, pr.second, 1);
    return 0;
}