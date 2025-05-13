#include"bits/stdc++.h"
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1,0);
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        arr[i]^=arr[i-1];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<(arr[a-1]^arr[b])<<endl;
    }
}