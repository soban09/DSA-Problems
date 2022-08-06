// same as Prims Algo
// difference
//  Prims : weight[v]=edgeWeight
//  Dijkstra : weight[v]=edgeWeight+weight[u]
// using parent is only for printing MST/route

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

void BellmanFord(vector<pi> graph[], int n){
    vector<int> weight(n, INT16_MAX);
    weight[0]=0;
    int noOFvertex=n-1;

    while(noOFvertex--){
        for(int u=0; u<n; u++){
            for(auto &[w,v]:graph[u]){
                if(weight[v]>w+weight[u])
                    weight[v]=w+weight[u];
            }
        }
    }

    // shortest path to every vertex from 0 : 
    for(int i=0; i<n; i++){
        cout<<i<<" : "<<weight[i]<<endl;
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pi> graph[n];
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({w,v});
    }

    BellmanFord(graph, n);
    
return 0;
}

// weighted graph
// 5 7
// 0 1 10
// 0 2 20
// 1 2 30
// 1 3 5
// 3 4 8
// 2 3 15
// 2 4 6
