#include "bits/stdc++.h"
// #include <bits/stdc++.h>
#define longlong int;
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    map<int,pair<int,int> > mp;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp.insert(make_pair(y-x,make_pair(x,y)));
    }
    int res=0;
    int time=0;
    for(auto it=mp.rbegin();it!=mp.rend();++it) {
        time+=it->second.first;
        res+=it->second.second-time;
    }
    cout<<res<<endl;
}
