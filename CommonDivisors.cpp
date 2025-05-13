#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll x[n];
    ll cnt[1000001]={};
    for(int i=0;i<n;i++){
        cin>>x[i];
        cnt[x[i]]++;
    }
    for(int i=1000000;i>=1;i--){
        ll d=0;
        for(int j=i;j<=1000000;j+=i){
            d+=cnt[j];
        }
        if(d>=2){
            cout<<i;
            return 0;
        }
    }
}