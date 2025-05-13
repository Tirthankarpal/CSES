#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        arr[i]--;
    }
    vector<vector<ll>> parent(n);
    for(int i=0;i<n;i++){
        parent[i].push_back(i);
    }
    for(int i=1;i<n;i++){
        ll node=i-1;
        while(arr[node]!=0){
            parent[i].push_back(arr[node]);
            node=arr[node];
        }
    }
}