// Disjoint set or Union find algo for detecting cycle in a graph
// a graph can be represented by diff method over here cuz we need edges

#include<bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent, int i){
    if(parent[i]==-1) return i;
    return findParent(parent, parent[i]);
}

bool UnionFind(vector<pair<int,int>> graph, int n){
    vector<int> parent(n, -1);

    for(auto &[u,v]:graph){
        int x = findParent(parent, u);
        int y = findParent(parent, v);
        
        if(x==y) return true;
        
        // make v parent of u
        parent[u]=v;
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> graph;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph.push_back({u,v});
    }

    UnionFind(graph, n) ? cout<<"Yes" : cout<<"No";
    return 0;
}