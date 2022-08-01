#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> graph[], vector<bool> &visited){
    visited[v]=true;
    cout<<v<<" ";

    for(auto &u:graph[v]){
        if(!visited[u]){
            dfs(u, graph, visited);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(i, graph, visited);
    }
    return 0;
}