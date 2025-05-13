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
    vector<vector<int>> ans;
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
                        vector<int> v;
                        v.push_back(arr[i+1]);
                        v.push_back(arr[j+1]);
                        v.push_back(arr[it->second.first]);
                        v.push_back(arr[it->second.second]);
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                    }
                    it++;
                }
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"IMPOSSIBLE"<<endl;
}