#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q ;
    cin >>n;
    cin>>q;
    long long arr[n + 1];
    arr[0] = 0;
    for(int i=1;i<n+1;i++){
        long long num;
        cin>>num;
        arr[i] = arr[i-1] + num;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<arr[r] - arr[l-1]<<endl;
    }
}
