#include<bits/stdc++.h>
using namespace std;

bool DetectCycle(int v, vector<int> graph[], vector<bool> &visited, vector<bool> &recStack){
    visited[v]=true;
    recStack[v]=true;

    for(auto &u:graph[v]){
        if(!visited[u] && DetectCycle(u, graph, visited, recStack))
            return true;
        else if(recStack[u])
            return true;
    }
    recStack[v]=false;
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        // Directed graph
        graph[u].push_back(v);
    }

    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);
    bool ans=false;
    for(int i=0; i<n; i++){
        if(!visited[i] && DetectCycle(i, graph, visited, recStack)){
            ans=true;
            break;
        }
    }
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}