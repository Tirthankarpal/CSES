#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=5;i<=n;i+=5){
        if(i%5==0){
            int temp=i;
            while(temp%5==0){
                count++;
                temp/=5;
            }
        }
    }
    cout<<count<<endl;
}