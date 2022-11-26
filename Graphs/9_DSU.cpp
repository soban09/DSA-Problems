// Disjoint set or Union find algo for finding parent of a perticular node
// a graph can be represented by diff method over here cuz we need edges
// path compression just dont let graph become a linear DS like LL, instead it spreads it
// Idea is to find root and make root as parent of node 
// Attach smaller rank tree under root of high rank tree

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public : 
    vector<int> parent, rank;
        DisjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n);
            for(int i=0; i<n; i++)
                parent[i]=i;
        }

        int findParent(int node){
            if(node==parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }

        void makeParent(int u, int v){
            int parent1 = findParent(u);
            int parent2 = findParent(v);
            if(parent1==parent2) return;

            if(rank[parent1] < rank[parent2]){
                parent[parent1]=parent2;
            } else if(rank[parent1] > rank[parent2]){
                parent[parent2] = parent1;
            } else{
                parent[parent1]=parent2;
                rank[parent2]++;
            }
        }
};

int main(){
    // int n,e;
    // cin>>n>>e;

    vector<pair<int,int>> graph = {
      {0,3},{0,4},{1,3},{1,5},{2,4},{2,5}
	};

    DisjointSet dsu(6);
    for(auto &[u,v]:graph){
        dsu.makeParent(u,v);
    }
    for(auto p:dsu.parent)
    cout<<p<<" ";
    return 0;
}