#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll binexp(ll a,ll b){
    ll result=1;
    while(b>0){
        if(b&1){
            result=(result*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n;
    cin>>m;
    cout<<m+ceil((double)(binexp(m,n)-m)/(double)n)<<endl;
}
    