#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int binexp(int a,int b,int m){
    int result=1;
    while(b>0){
        if(b&1){
            result=(result*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b=b>>1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2==1)cout<<0<<endl;
    else cout<<1+binexp(2,(n/2)-2,1000000007)<<endl;
}