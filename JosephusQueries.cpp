#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll n,ll k)
{
    if(n==1) return 1;
    if(k<=(n+1)/2){
        if(2*k>n){
            return (2*k)%n;
        }
        else return 2*k;
    }
    ll temp=fun(n/2,k-(n+1)/2);
    if(n%2==1) {
        return 2*temp+1;
    }
    return 2*temp-1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll n,k;
        cin>>n>>k;
        cout<<fun(n,k)<<endl;
    }
}