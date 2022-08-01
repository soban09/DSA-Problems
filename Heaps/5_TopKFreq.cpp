#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, int> m;
typedef pair<int, int> p;
typedef priority_queue<p, vector<p>, greater<p>> pr;

vi TopKFreq(int *arr, int n, int k){
    pr Heap;
    vi v;
    m mp;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        Heap.push({it->second, it->first});
        if(Heap.size()>k){
            Heap.pop();
        }
    }

    while(!Heap.empty()){
        // cout<<Heap.top().first<<" ";
        v.push_back(Heap.top().second);
        Heap.pop();
    }
    return v;
}

int main(){
    int arr[] = {1,1,1,3,4,2,2};
    int n = sizeof(arr)/sizeof(int);
    vi v = TopKFreq(arr, n, 2);
    for(auto i:v) cout<<i<<" ";
    return 0;
}