#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1){
            cout<<0<<endl;
            continue;
        }
        if(i==2){
            cout<<6<<endl;
            continue;
        }
        if(i==3){
            cout<<28<<endl;
            continue;
        }
        if(i==4){
            cout<<96<<endl;
            continue;
        }
        if(i==5){
            cout<<252<<endl;
            continue;
        }
        if(i==6){
            cout<<550<<endl;
            continue;
        }
        if(i==7){
            cout<<1056<<endl;
            continue;
        }
        if(i==8){
            cout<<1848<<endl;
            continue;
        }
        long long total=0;
        total+=((i-4)*1LL*(i-4))*((i*1LL*i)-9);
        total+=4*((i*1LL*i)-5);
        total+=8*((i*1LL*i)-4);
        total+=4*((i*1LL*i)-3);
        total+=(i-4)*4*((i*1LL*i)-5);
        total+=(i-4)*4*((i*1LL*i)-7);
        cout<<total/2<<endl;
    }
}