#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class SGTree{
    vector<int> seg;
    public :
        SGTree(int n){
            seg.resize(4*n+1);
        }

        void build(int idx, int low, int high, int *arr){
            if(low==high){
                seg[idx]=arr[low];
                return;
            }
            
            int mid=(low+high) >> 1;
            build(2*idx+1, low, mid, arr);
            build(2*idx+2, mid+1, high, arr);
            seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
        }

        int query(int idx, int low, int high, int l, int r){
            //no overlapping
            // low high l r   or  l r low  high
            if(high<l || r<low)
                return 1e8;
             
            //complete overlapping
            // l low high r
            if(l<=low && high<=r)
                return seg[idx];

            //partial overalapping
            int mid = (low+high) >> 1;
            int left = (2*idx+1, low, mid, l, r);
            int right = (2*idx+2, mid+1, high, l ,r);

            return min(left, right); 
        }

        void update(int idx, int low, int high, int i, int val){
            if(low==high){
                seg[low] = val;
                return;
            }

            int mid = (low+high) >> 1;
            if(i>=mid)
                update(2*idx+1, low, mid, i, val);
            else
                update(2*idx+2, mid+1, high, i, val);
            seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
        }
};

void solve(){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0; i<n1; i++) cin>>arr1[i];
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);

    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0; i<n2; i++) cin>>arr2[i];
    SGTree sg2(n2);
    sg2.build(0,0,n2-1,arr2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1 = sg1.query(0,0,n1-1,l1,r1);
            int min2 = sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1, min2);
        }
        else{
            int arrNo, i, val;
            cin>>arrNo>>i>>val;
            if(arrNo==1){
                sg1.update(0,0,n1-1,i,val);
                arr1[i]=val;
            }
            else{
                sg2.update(0,0,n2-1,i,val);
                arr2[i]=val;
            }
        }
    }
}

int main()
{   
    return 0;
}