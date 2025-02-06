#include "bits/stdc++.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,bool> m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x]=true;
    }
    cout<<"the size is = "<<m.size()<<endl;
}