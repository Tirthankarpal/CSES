#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        if(a>2*b||b>2*a){
            cout<<"NO"<<endl;
            continue;
        }
        a=a%3;
        b=b%3;
        if(a+b==3||a+b==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}