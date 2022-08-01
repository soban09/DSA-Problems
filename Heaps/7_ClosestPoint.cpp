#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

typedef pair<int, int> p;
typedef vector<p> vi;
// Max Heap
typedef priority_queue<pair<int, p>> pr;

float Dist(int x, int y) { return sqrt(x*x+y*y); }

p ClosestPoint(vi v){
    pr Heap;

    for(auto i:v){
        float dist = Dist(i.first, i.second);
        Heap.push({dist, i});
        if(Heap.size()>1) Heap.pop();
    }

    return Heap.top().second;
}

int main(){
    vi points{{0,1}, {-2,2}, {1,3}, {5,8}};
    p pair = ClosestPoint(points);
    cout<<"("<<pair.first<<","<<pair.second<<")";
    return 0;
}