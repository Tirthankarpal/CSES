#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<pair<int,int> > s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top().first>=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            cout<<s.top().second<<" ";
        }
        else{
            cout<<0<<" ";
        }
        s.push(make_pair(arr[i],i+1));
    }
}