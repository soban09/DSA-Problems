#include<iostream>
#include<vector>
using namespace std;

int RatInAMAze(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
//         first coloumn
        for(int i=0; i<r; i++){
            if(grid[i][0]==0) grid[i][0]=1;
            else break;
        }
        
//         first row
        for(int j=1; j<c; j++){
            if(grid[0][j]==0) grid[0][j]=1;
            else break;
        }
        
//         in between
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                if(grid[i][j]==-1) continue;
                
                if(grid[i-1][j] > 0){
                    grid[i][j]+=grid[i-1][j];
                }
                
                if(grid[i][j-1] > 0){
                    grid[i][j]+=grid[i][j-1];
                }
            }
        }
        return grid[r-1][c-1];
    }

    void print(vector<vector<int>> grid){
        for(auto i:grid){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

int main(){
    // vector<vector<int>> grid{{0,0,0,0},{0,-1,0,0},{-1,0,0,0},{0,0,0,0}};
    // vector<vector<int>> grid{{0,0,0},{0,-1,0},{0,0,0}};

    int A=25,B=1;
    int mid=A/2;
    
    vector<vector<int>> grid(A, vector<int>(A, 0));
    grid[mid][mid]=-1;
    
    int i=1;
    while(i<=B){
        
        for(int j=mid-i; j<=mid+i; j++){
            grid[mid-i][j]=-1;
            grid[mid+i][j]=-1;
            grid[j][mid-i]=-1;
            grid[j][mid+i]=-1;
        }
        i++;
    }

    print(grid);
    cout<<RatInAMAze(grid);
    return 0;
}