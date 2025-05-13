#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    cin>>x;
    long long arr[n];
    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        arr[i]=num;
    }
    sort(arr,arr+n);
    int res=0;
    int i=0;
    int j=n-1;
    while(j>=i){
        if(arr[i]+arr[j]<=x){
            res++;
            i++;
            j--;
        }
        else{
            res++;
            j--;
        }
    }
    cout<<res<<endl;
}