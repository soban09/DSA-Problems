#include<iostream>
#include<unordered_map>
using namespace std;

int LargestSubArrWithGivenSum(int *arr, int n, int k){
    int i=0,j=0,mx=-1,sum=0;

    while(j<n){
        sum+=arr[j];
        
        // if(sum < k)
        //     j++;

        if(sum == k)
            mx = max(mx, j-i+1);

        else if(sum > k){
            while(sum > k){
                sum-=arr[i];
                i++;
            }
        }
        j++;
    }
    return mx;
}

// will work for negative numbers too
int LargestSubArrWithGivenSum2(int arr[],  int n, int k) 
 { 
    unordered_map<int,int> mp;
    int len=0,sum=0;
    mp[0]=-1;
          
    for(int i=0;i<n;i++){
        sum+=arr[i];
            
        if(mp.find(sum-k)!=mp.end()){
            len=max(len,i-mp[sum-k]);
        }
            
        if(mp.find(sum)==mp.end())
        mp[sum]=i;
    }
    return len;
} 

int main(){
    int arr[] = {4,1,1,1,2,3,5};
    cout<<LargestSubArrWithGivenSum(arr,7,5);
    return 0;
}