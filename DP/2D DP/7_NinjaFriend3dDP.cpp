#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//fixed starting to variable ending

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
int m,n;

int CherryPickup(vvi grid, int i, int aj, int bj, vvvi &dp){
    if(aj<0 || bj<0 || aj>=n || bj>=n)
        return -1e8;

    if(i==m-1){
        if(aj==bj) //if they reach the same pos, only 1 will take
            return grid[i][aj];
        else 
            return grid[i][aj]+grid[i][bj];
    }

    if(dp[i][aj][bj]!=-1)
        return dp[i][aj][bj];
    // every person has 3 choice, hence no of combos = 3x3 = 9
    //write 9 function calls or write a nested loop

    int mx=-1e+8;
    for(int na=-1; na<=1; na++){
        for(int nb=-1; nb<=1; nb++){
            int value=0;
            if(aj==bj)
                value=grid[i][aj] + CherryPickup(grid, i+1, aj+na, bj+nb, dp);
            else 
                value=grid[i][aj]+grid[i][bj]+CherryPickup(grid, i+1, aj+na, bj+nb, dp);
            mx = max(mx, value);
        }
    }
    return dp[i][aj][bj]=mx;
}

int CherryPickupDP(vvi grid){
    vvvi dp(m, vvi(n, vi(n, -1))); 

    for(int j1=0; j1<n; j1++){
        for(int j2=0; j2<n; j2++){
            if(j1==j2) dp[m-1][j1][j2] = grid[m-1][j1];
            else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
        }
    }

    for(int i=m-2; i>=0; i--){
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                
                int mx=-1e8;
                for(int na=-1; na<=1; na++){
                    for(int nb=-1; nb<=1; nb++){

                        int value=-1e8;
                        if(j1+na >=0 && j1+na < n && j2+nb>=0 && j2+nb < n){
                            if(j1==j2)
                                value = grid[i][j1] + dp[i+1][j1+na][j2+nb];
                            else 
                                value = grid[i][j1] + grid[i][j2] + dp[i+1][j1+na][j2+nb];
                        }

                        mx = max(mx, value);
                    }
                }
                dp[i][j1][j2]=mx;
            }
        }
    }
    return dp[0][0][n-1];
}

int main()
{   
    vvi grid{{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    m=3,n=4;

    vvvi dp(m, vvi(n, vi(n, -1))); 
    cout<<CherryPickup(grid,0,0,n-1, dp)<<endl;
    cout<<CherryPickupDP(grid);
    return 0;
}