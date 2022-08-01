// Max area Histogram
// push n instead of -1 in NSR

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> NSL(int *arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size()==0)
            v.push_back(-1);

        else if(s.size()>0 && arr[s.top()]<arr[i])
            v.push_back(s.top());

        else if(s.size()>0 && arr[s.top()]>=arr[i]){
            while(s.size()>0 && arr[s.top()]>=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(i);
    }
    return v;
}

vector<int> NSR(int *arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        if(s.size()==0)
            v.push_back(n);

        else if(s.size()>0 && arr[s.top()]<arr[i])
            v.push_back(s.top());

        else if(s.size()>0 && arr[s.top()]>=arr[i]){
            while(s.size()>0 && arr[s.top()]>=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(n);
            else
                v.push_back(s.top());
        }
        s.push(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int MaxAreaHisto(int *arr, int n){
    vector<int> nsr = NSR(arr, n);
    vector<int> nsl = NSL(arr, n);

    int mx=-1;
    for(int i=0; i<n; i++){
        int area = arr[i]*(nsr[i]-nsl[i]-1);
        mx = max(mx, area);
    }
    return mx;
}

int main(){
    int arr[] = {6,2,5,4,5,1,6};
    cout<<MaxAreaHisto(arr, 6);
    return 0;
}