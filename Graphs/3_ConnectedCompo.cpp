#include<bits/stdc++.h>
using namespace std;

//does nothing but goes DFS and marks+count nodes visited
void countConnectedCompo(vector<int> adj[], vector<bool> &visited, int src, int &count){
    visited[src]=true;
    count++;
    for(auto x:adj[src]){
        if(!visited[x]){
            countConnectedCompo(adj,visited,x,count);
        }
    }    
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> adj[n];
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n,false);
    vector<int> Comps;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            int count=0;
            countConnectedCompo(adj,visited,i,count);
            Comps.push_back(count);
        }
    }
    for(int i:Comps)cout<<i<<" ";
    cout<<endl;
    cout<<Comps.size()<<endl;

    //if no of ways two persons can be choosed from non conncted subgraphs then : 
    // Ans = Sum(nC2)
    long long int sum=0;
    for(int i:Comps){
        sum+=i*(n-i);
    }
    cout<<sum/2;

return 0;
}

