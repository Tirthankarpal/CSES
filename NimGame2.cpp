#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int f=0;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            f^=(x%4);
        }
        if(f==0)cout<<"second"<<endl;
        else cout<<"first"<<endl;
    }
}