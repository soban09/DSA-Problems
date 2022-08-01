#include<iostream>
using namespace std;

pair<int, int> BS(int arr[][4], int n, int m, int e){
    int i=0, j=m-1;
    while(i>=0 && j>=0 && i<n && j<m){
        if(arr[i][j]==e){
            return {i,j};
        }
        else if(arr[i][j]>e) j--;
        else i++;
    }
    return {-1, -1};
}

int main(){
    int arr[4][4] = {{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
    pair<int, int> p; 
    p = BS(arr, 4, 4, 29);
    cout<<p.first<<" "<<p.second;
    return 0;
}