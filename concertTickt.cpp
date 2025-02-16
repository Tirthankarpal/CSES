#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    cin>>m;
    multiset<int> arr;
    int brr[m];
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.insert(num);
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        brr[i]=num;
    }
    for(int i=0;i<m;i++){
        auto it=arr.lower_bound(brr[i]);
        if(it==arr.end()){
            if(arr.size()==0){
                cout<<-1<<endl;
                continue;
            }else it--;
        }
        if(*it>brr[i]){
            if(it==arr.begin()){
                cout<<-1<<endl;
                continue;
            }else it--;
        }
        cout<<*it<<endl;
        arr.erase(it);
    }
}