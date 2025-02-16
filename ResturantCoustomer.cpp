#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<pair<int,int> > set1;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        set1.insert(make_pair(x,1));
        set1.insert(make_pair(y,-1));
    }
    int res=0;
    int count=0;
    for(auto c: set1){
        count+=c.second;
        res=max(res,count);
    }
    cout<<res<<endl;
}