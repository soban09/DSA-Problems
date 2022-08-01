#include<bits/stdc++.h>
using namespace std;

bool DetectCycle(int v, vector<int> graph[], vector<bool> &visited, int parent){
    visited[v]=true;

    for(auto &u:graph[v]){
        if(!visited[u] && DetectCycle(u, graph, visited, v))
            return true;
        else if(u!=parent)
            return true;
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        //un Directed graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool ans=false;
    for(int i=0; i<n; i++){
        if(!visited[i] && DetectCycle(i, graph, visited, -1)){
            ans=true;
            break;
        }
    }
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}