#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
long long expo(long long a,long long b){
    long long result=1;
    while (b>0) {
        if(b%2==1) {
            result=(result*a)%1000000007;
        }
        a=(a*a)%1000000007;
        b/=2;
    }
    return result;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<expo(a,b)<<endl;
    }
}