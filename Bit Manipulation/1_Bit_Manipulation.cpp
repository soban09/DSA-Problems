#include<iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}

int setIthBit(int n, int i){
    int mask = (1<<i);
    return (n|mask);
}

int clearIthBit(int n, int i){
    int mask = ~(1<<i);
    return (n&mask);
}

int updateIthBit(int n, int i, int v){
    n = clearIthBit(n,i);
    int mask = (v<<i);
    return (n|mask);
}

int clearNthBits(int n, int i){
    int mask = (-1 << i);
    return (n&mask);
}

int clearBitsInRange(int n, int i, int j){
    int a = (-1 << j+1);
    int b = ((1<<i) - 1);
    int mask = a|b;
    return (n&mask);
}

int main(){
    cout<<getIthBit(36,3)<<endl;
    cout<<getIthBit(49,3)<<endl;
    cout<<getIthBit(30,3)<<endl;
    cout<<getIthBit(34,3)<<endl;
    cout<<getIthBit(11,3)<<endl;
    cout<<getIthBit(31,3)<<endl;
    cout<<getIthBit(42,3)<<endl;
    cout<<getIthBit(11,3)<<endl;
    cout<<getIthBit(35,3)<<endl;
    cout<<getIthBit(3,3)<<endl;
    
    return 0;
}