#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
const int n=(2*1e6)+5;
int fac[n];
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
    fac[0]=1;
    for(int i=1;i<n;i++){
        fac[i]=(1LL*i*fac[i-1])%(1000000007);
    }
    string str;
    cin>>str;
    int arr[26]={0};
    for(int i=0;i<str.length();i++){
        arr[str[i]-'a']++;
    }
    int denom=1;
    for(int i=0;i<26;i++){
        if(arr[i]>0)denom=(denom*1LL*fac[arr[i]])%1000000007;
    }
    int ans=fac[str.length()];
    ans=(ans*1LL*binexp(denom,1000000005,1000000007))%1000000007;
    cout<<ans<<endl;
}