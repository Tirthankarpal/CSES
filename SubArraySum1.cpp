#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
#define longlong long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int arr[n];
    queue<int> q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int j=0;
    int res=0;
    int sum=0;
    while(j<n||sum>x){
        if(sum==x){
            sum+=arr[j];
            res++;
            j++;
        }
        else if(sum<x&&j<n){
            sum+=arr[j];
            j++;
        }
        else{
            i++;
            sum-=arr[i-1];
        }
    }
    if(sum==x){
        res++;
    }
    cout<<res<<endl;
}
