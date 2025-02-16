#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    cin>>x;
    map<int,int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(arr[x-num]){
            cout<<arr[x-num]<<" "<<i+1<<endl;
            arr.erase(x-num);
            return 0;
        }
        arr[num]=i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
}