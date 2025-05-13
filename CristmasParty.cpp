#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int good(ll n){
    if(n==0)return 1;
    return (n*good(n-1)+(ll)pow(-1,n))%1000000007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<good(n)<<endl;
}