#include<iostream>
using namespace std;

int clearBitsInRange(int n, int i, int j){
    int a = (-1 << j+1);
    int b = ((1<<i) - 1);
    int mask = a|b;
    return (n&mask);
}

int ReplaceBits(int n, int m, int i, int j){
    n = clearBitsInRange(n,i,j);
    m = (m<<i);
    return n|m;
}

int main(){
    cout<<ReplaceBits(1024, 25, 2, 6)<<endl;
    cout<<ReplaceBits(15, 2, 1, 3)<<endl;
    return 0;
}