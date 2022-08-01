#include<iostream>
using namespace std;

char NextLetter(char *arr, int n, char e){
    int mid, start=0, end=n-1;
    char res='-';

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==e) start=mid+1;

        else if(arr[mid]>e){
            res=arr[mid];
            end=mid-1;
        }
        else start=mid+1;
    }
    return res;
}

int main(){
    char arr[] = {'a', 'b', 'f', 'h'};
    int n = sizeof(arr)/sizeof(char);

    cout<<NextLetter(arr,n,'f');
    return 0;
}