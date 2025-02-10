#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multimap<long long,pair<int,int> > m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m.insert(make_pair(arr[i]+arr[j],make_pair(i+1,j+1)));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(m.find(x-arr[i]-arr[j])!=m.end()){
                auto it=m.find(x-arr[i]-arr[j]);
                while(it!=m.end()&&it->first==x-arr[i]-arr[j]){
                    if(it->second.first!=i+1&&it->second.second!=i+1&&it->second.first!=j+1&&it->second.second!=j+1){
                        cout<<i+1<<" "<<j+1<<" "<<it->second.first<<" "<<it->second.second<<endl;
                        return 0;
                    }
                    it++;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}