#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b;
    cin>>n;
    if (n<3||((n+1)/2)%2==1)
    {
       cout<<"NO"<<endl;
       return 0;
    }
    cout<<"YES"<<endl;
    if(n%2==0){
        cout<<n/2<<endl;
        for(int i=1;i<n;i+=2){
            if(i<=n/2){
                cout<<i+1<<" ";
            }
            else cout<<i<<" ";
        }
        cout<<endl<<n/2<<endl;
        for(int i=2;i<=n;i+=2){
            if(i<=n/2){
                cout<<i-1<<" ";
            }
            else cout<<i<<" ";
        }
    }
    else{
        cout<<(n/2+1)<<endl;
        cout<<"1 ";
        for(int i=3;i<=n;i+=2){
            if(i<=(n+1)/2+1){
                cout<<i-1<<" ";
            }
            else cout<<i<<" ";
        }
        cout<<endl<<n/2<<endl;
        for(int i=2;i<=n;i+=2){
            if(i<=(n+1)/2){
                cout<<i+1<<" ";
            }
            else cout<<i<<" ";
        }
    }
}