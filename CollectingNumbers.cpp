#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i]-1)==s.end()){
            res++;
            s.insert(arr[i]);
        }
        else {
            s.insert(arr[i]);
        }
    }
    cout<<res<<endl;
}