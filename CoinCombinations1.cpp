#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n;
    cin>>x;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    vector<long long> arr(x+1,0);
    arr[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-arr1[j]>=0){
                arr[i]+=arr[i-arr1[j]];
                arr[i]%=1000000007;
            }
        }
    }
    cout<<arr[x]<<endl;
}