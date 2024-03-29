// Nearest Greater to Right

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> NGR(int *arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=n-1; i>=0; i--){
        if(s.size()==0)
            v.push_back(-1);

        else if(s.size()>0 && s.top()>arr[i])
            v.push_back(s.top());

        else if(s.size()>0 && s.top()<=arr[i]){
            while(s.size()>0 && s.top()<=arr[i])
                s.pop();

            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    // vector<int> v(n,-1);
    // // another code
    // for(int i=0; i<n; i++){
    //     while(!s.empty() && arr[s.top()] < arr[i]){
    //         v[s.top()]=arr[i];
    //         s.pop();
    //     }
    //     s.push(i);
    // }
    reverse(v.begin(), v.end());
    return v;
}

int main(){
    int arr[] = {10,6,8,5,11,9};
    vector<int> v = NGR(arr, 6);
    for(auto a:v) cout<<a<<" ";
    return 0;
}