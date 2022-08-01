#include<iostream>
using namespace std;

int main(){
    auto powerOf2 = [&](int n){
        return (n & n-1)>0 ? 0 : 1;
    };
    cout<<powerOf2(16)<<endl;
    cout<<powerOf2(15)<<endl;
    cout<<powerOf2(8)<<endl;
    cout<<powerOf2(24)<<endl;
    return 0;
}