#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    multimap<int,int> m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        m.insert(make_pair(num,i+1));
    }
    for(auto c:m){
        int val=c.first;
        int idx=c.second;
        for(auto d:m){
            int val1=d.first;
            int idx1=d.second;
            if(idx==idx1) continue;
            auto it=m.find(x-(val+val1));
            while(it!=m.end()&&it->first==x-(val+val1)){
                if(it->second!=idx&&it->second!=idx1){
                    cout<<idx<<" "<<idx1<<" "<<it->second<<endl;
                    return 0;
                }
                it++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}