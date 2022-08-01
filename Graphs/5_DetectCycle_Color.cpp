// WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.
// GRAY: Vertex is being processed (DFS for this vertex has started, but not finished which means that all descendants (in DFS tree) of this vertex are not processed yet (or this vertex is in the function call stack)
// BLACK : Vertex and all its descendants are processed. While doing DFS, if an edge is encountered from current vertex to a GRAY vertex, then this edge is back edge and hence there is a cycle. 

#include<bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

bool DetectCycle(int v, vector<int> graph[], vector<int> &color){
    color[v] = GRAY;

    for(auto &u:graph[v]){
        if(color[u]==WHITE && DetectCycle(u, graph, color))
            return true;
        else if(color[u]==GRAY)
            return true;
    }
    color[v]=BLACK;
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

    vector<int> color(n, WHITE);
    bool ans=false;
    for(int i=0; i<n; i++){
        if(color[i]==WHITE && DetectCycle(i, graph, color)){
            ans=true;
            break;
        }
    }
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}