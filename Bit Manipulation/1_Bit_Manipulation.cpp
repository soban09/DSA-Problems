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
    cout<<getIthBit(13,1)<<endl;
    cout<<setIthBit(13,1)<<endl;
    cout<<clearIthBit(13,0)<<endl;
    cout<<updateIthBit(13,2,0)<<endl;
    cout<<clearNthBits(13,3)<<endl;
    cout<<clearBitsInRange(31,1,3)<<endl;
    return 0;
}