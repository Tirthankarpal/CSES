#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long binexp(long long a,long long b,long long m){
    int result=1;
    while(b>0){
        if(b&1){
            result=(result*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return result;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long a,b,c;
        cin>>a>>b>>c;
        long ans=binexp(b,c,mod-1);
        cout<<binexp(a,ans,mod)<<endl;
    }
}
