#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    auto check = [&](int i, int j){
        return (0<=i and 0<=j and i<n and j<m);
    };

    vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    function<void(int, int)> dfs = [&](int i, int j){
        grid[i][j]='$';
        for(auto &[di, dj] : dir){
            int newi=i+di, newj=j+dj;
            if(check(newi, newj) && grid[newi][newj]=='1'){
                dfs(newi, newj);
            }
        }
    };

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1'){
                dfs(i,j);
                ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}

// 4 5 1 1 0 0 0 0 1 1 0 1 1 1 0 0 0 0 0 0 1 1