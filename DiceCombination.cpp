#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> arr(n+1);
    arr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                arr[i]+=arr[i-j];
                arr[i]%=1000000007;
            }
        }
    }
    cout<<arr[n]<<endl;
}
