#include<iostream>
using namespace std;

int main(){
    auto evenOdd = [&](int n){
        return (n&1);
    };
    cout<<evenOdd(6)<<endl;
    cout<<evenOdd(5)<<endl;
    cout<<evenOdd(3)<<endl;
    cout<<evenOdd(2)<<endl;
    return 0;
}