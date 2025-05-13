#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(m);
    for (int i=0;i<m;i++) {
        cin>>arr[i];
    }
    vector<ll> count(m+1,0);
    for(int i=1;i<(1<<m);i++){
        int num=0;
        ll temp=n;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                num++;
                temp/=arr[j];
            }
        }
        if(num%2==0){
            count[num]-=temp;
        }
        else{
            count[num]+=temp;
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+count[i]);
    }
    cout<<ans<<endl;
}