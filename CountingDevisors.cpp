#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int div(int a){
    int count=0;
    for(int i=1;i<sqrt(a);i++){
        if(a%i==0){
            count+=2;
        }
    }
    if(a==(int)sqrt(a)*(int)sqrt(a)){
        count++;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        cout<<div(a)<<endl;
    }
}