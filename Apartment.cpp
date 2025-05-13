#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    int arr[n];
    int brr[m];
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr[i]=num;
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        brr[i]=num;
    }
    sort(arr,arr+n);
    sort(brr,brr+m);
    int res=0;
    int j=0;
    for(int i=0;i<m;i++){
            while(j<n){
                if(brr[i]-arr[j]<-k){
                    break;
                }
                else if(brr[i]-arr[j]>=-k&&brr[i]-arr[j]<=k){
                    j++;
                    res++;
                    break;
                }
                else{
                    j++;
                }
            }
        }
        cout<<res<<endl;
}