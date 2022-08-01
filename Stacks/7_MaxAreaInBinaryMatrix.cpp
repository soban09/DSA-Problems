// points to remember:-
// insert n instead of -1 in vector in NSR function

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> NSR(vector<int> arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        if(s.size()==0) v.push_back(n);

        else if(s.size()>0 && arr[s.top()]<arr[i]){
            v.push_back(s.top());
        }

        else if(s.size()>0 && arr[s.top()]>=arr[i]){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0) v.push_back(n);
            else v.push_back(s.top());
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> NSL(vector<int> arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size()==0) v.push_back(-1);

        else if(s.size()>0 && arr[s.top()]<arr[i]){
            v.push_back(s.top());
        }

        else if(s.size()>0 && arr[s.top()]>=arr[i]){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(i);
    }
    return v;
}

int MAH(vector<int> arr, int n){
    vector<int> nsr = NSR(arr, n);
    vector<int> nsl = NSL(arr, n);
    int mx=0;

    for(int i=0; i<n; i++){
        mx = max(mx, arr[i]*(nsr[i]-nsl[i]-1));
    }
    return mx;
}

// m = rows, n = col
int MaxAreaBinaryMatrix(int arr[][4], int m, int n){
    vector<int> v;
    int mx = 0;
    for(int j=0; j<n; j++){
        v.push_back(arr[0][j]);
    }
    mx = MAH(v, n);

    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0) v[j]=0;
            else v[j]+=arr[i][j];
        }
        mx = max(mx, MAH(v, n));
    }
    return mx;
}

int main(){
    int arr[4][4] = {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
    cout<<MaxAreaBinaryMatrix(arr, 4, 4);
    return 0;
}