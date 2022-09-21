// Nearest Smaller to Right

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NSR(int *arr, int n){
    vector<int> v;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--){
        if (s.size() == 0)
            v.push_back(-1);

        else if (s.size() > 0 && s.top() < arr[i])
            v.push_back(s.top());

        else if (s.size() > 0 && s.top() >= arr[i]){
            while (s.size() > 0 && s.top() >= arr[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    // vector<int> v(n,-1);
    // for(int i=0; i<n; i++){
    //     while(!s.empty() && arr[s.top()]>arr[i]){
    //         v[s.top()]=arr[i];
    //         s.pop();
    //     }
    //     s.push(i);
    // }
    return v;
}

int main(){
    int arr[] = {4, 5, 2, 10, 8};
    vector<int> v = NSR(arr, 5);
    for (auto a : v)
        cout << a << " ";
    return 0;
}