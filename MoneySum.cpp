#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(mp[arr[i]]==0){
            mp[arr[i]]=i+1;
        }
        for(auto it:mp){
            if(mp[it.first]!=i+1&&mp[it.first+arr[i]]==0){
                mp[it.first+arr[i]]=i+1;
            }
        }
    }
    cout<<mp.size()<<endl;
    for(auto it:mp){
        cout<<it.first<<" ";
    }
}