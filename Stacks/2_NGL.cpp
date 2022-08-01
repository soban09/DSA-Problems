// Nearest Greater to Left

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> NGL(int *arr, int n){
    // vector<int> v(n);
    stack<int> s;

    // for (int i = 0; i < n; i++){
    //     if (s.size() == 0)
    //         v.push_back(-1);

    //     else if (s.size() > 0 && s.top() > arr[i])
    //         v.push_back(s.top());

    //     else if (s.size() > 0 && s.top() <= arr[i]){
    //         while (s.size() > 0 && s.top() <= arr[i])
    //             s.pop();
    //         if (s.size() == 0)
    //             v.push_back(-1);
    //         else
    //             v.push_back(s.top());
    //     }
    //     s.push(arr[i]);
    // }

    vector<int> v(n,-1);
    // another code
    for(int i=n-1; i>0; i--){
        while(!s.empty() && arr[s.top()] < arr[i]){
            v[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    return v;
}

int main(){
    int arr[] = {1, 3, 2, 4};
    vector<int> v = NGL(arr, 4);
    for (auto a : v)
        cout << a << " ";
    return 0;
}