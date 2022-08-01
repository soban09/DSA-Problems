#include<bits/stdc++.h>
using namespace std;

int MinStepCost(int a, int b, int m, int n, int **arr){
    if((a==(m-2)) && (b==(n-2))){
        return arr[a][b]+arr[a+1][b+1];
    }
    
    if(a == (m-1)){
        int sum=0;
        for(int i=b+1; i<n; i++){
            sum+=arr[a][i];
        }
        return sum;
    }

    if(b == (n-1)){
        int sum=0;
        for(int i=a+1; i<m; i++){
            sum+=arr[i][b];
        }
        return sum;
    }

    int nextcost=0;
    int currentCost = min(arr[a+1][b+1], min(arr[a][b+1], arr[a+1][b]));

    if(currentCost == arr[a+1][b+1]){
        nextcost = MinStepCost(a+1, b+1, m, n, arr);
    }
    else if(currentCost == arr[a][b+1]){
        nextcost = MinStepCost(a, b+1, m, n, arr);
    }
    else{
        nextcost = MinStepCost(a+1, b, m, n, arr);
    }

    return arr[a][b]+nextcost;
}

int MinStepCost_Better_Helper(int **arr, int m, int n, int a, int b, int **ans){
    if(a==m-1 && b==n-1){
        return arr[a][b];
    }

    if(a>=m || b>=n){
        return INT_MAX;
    }

    if(ans[a][b] != -1){
        return ans[a][b];
    }

    int x = MinStepCost_Better_Helper(arr, m, n, a+1, b+1, ans);
    if(x<INT_MAX){
        ans[a+1][b+1]=x;
    }
    int y = MinStepCost_Better_Helper(arr, m, n, a, b+1, ans);
    if(y<INT_MAX){
        ans[a][b+1]=y;
    }
    int z = MinStepCost_Better_Helper(arr, m, n, a+1, b, ans);
    if(z<INT_MAX){
        ans[a+1][b]=z;
    }
    
    ans[a][b] = min(x, min(y,z)) + arr[a][b];
    return ans[a][b];
}

int MinStepCost_Better(int m, int n, int **arr){
    int **ans = new int*[m];
    for(int i=0; i<m; i++){
        ans[i] = new int[n];
        for(int j=0; j<n; j++){
            ans[i][j]=-1;
        }
    }
    return MinStepCost_Better_Helper(arr, m, n, 0, 0, ans);
}

int MinStepCost_DP(int m, int n, int **arr){
    int **ans = new int*[m];
    for(int i=0; i<m; i++){
        ans[i] = new int[n];
    }

    ans[m-1][n-1] = arr[m-1][n-1];
    
    //Last Row
    for(int j=n-2; j>=0; j--){
        ans[m-1][j] = arr[m-1][j] + ans[m-1][j+1];
    }

    //Last Coloumn
    for(int i=m-2; i>=0; i--){
        ans[i][n-1] = arr[i][n-1] + ans[i+1][n-1]; 
    }

    //remaining
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            ans[i][j] = arr[i][j] + min(ans[i+1][j+1], min(ans[i][j+1], ans[i+1][j]));
        }
    }
    return ans[0][0];
}

int main(){
    int n,m;
    cin>>m>>n;

    int **arr = new int*[m];
    for(int i=0; i<m; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<MinStepCost(0,0,m,n, arr)<<endl;
    cout<<MinStepCost_Better(m,n, arr)<<endl;
    cout<<MinStepCost_DP(m,n, arr)<<endl;

return 0;
}