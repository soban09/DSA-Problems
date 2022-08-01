#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

vector<int> KClosest(int *arr, int n, int k, int X){
    vector<int> v;
    priority_queue<pi> Heap;

    for(int i=0; i<n; i++){
        pi p;
        p.first = abs(arr[i]-X);
        p.second = arr[i];
        Heap.push(p);

        if(Heap.size()>k){
            Heap.pop();
        }
    }

    while(!Heap.empty()){
        v.push_back(Heap.top().second);
        Heap.pop();
    }
    return v;
}

int main(){
    int arr[] = {5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    vector<int> v = KClosest(arr, n, 3, 7);
    for(auto i:v) cout<<i<<" ";
    return 0;
}