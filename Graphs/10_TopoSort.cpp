// Only for DAG

#include<bits/stdc++.h>
using namespace std;

void dfs(int v, stack<int> &s, vector<int> graph[], vector<bool> &vis){
    vis[v]=true;
    for(auto &u:graph[v]){
        if(!vis[u]) dfs(u, s, graph, vis);
    }
    s.push(v);
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        //DAG
        graph[u].push_back(v);
    }
    stack<int> s;
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i, s, graph, vis);
    }

    vector<int> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    for(auto a:v) cout<<a<<" ";
    return 0;
}