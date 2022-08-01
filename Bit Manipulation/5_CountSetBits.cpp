#include<iostream>
using namespace std;

int countSetBits(int n){
    int c=0;
    while(n>0){
        c+=(n&1);
        n=n>>1;
    }
    return c;
}

int countSetBitsFaster(int n){
    int c=0;
    while(n>0){
        n = (n & n-1);
        c++;
    }
    return c;
}

int main(){
    cout<<countSetBits(63)<<endl;
    cout<<countSetBitsFaster(63)<<endl;
    cout<<countSetBits(5)<<endl;
    cout<<countSetBitsFaster(5)<<endl;
    return 0;
}