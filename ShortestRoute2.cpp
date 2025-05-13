#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long> > arr(n,vector<long long>(n,LONG_MAX));
    for(int i=0;i<n;i++){
        arr[i][i]=0;
    }
    for (long long i = 0; i < m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        arr[x-1][y-1]=min(arr[x-1][y-1],z);
        arr[y-1][x-1]=min(arr[y-1][x-1],z);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i)continue;
            for(int k=0;k<n;k++){
                if(k==i)continue;
                if(arr[j][i]!=LONG_MAX&&arr[i][k]!=LONG_MAX&&arr[j][k]>arr[j][i]+arr[i][k]){
                    arr[j][k]=arr[j][i]+arr[i][k];
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        long long x,y;
        cin>>x>>y;
        if(arr[x-1][y-1]==LONG_MAX){
            cout<<-1<<endl;
        }else{
            cout<<arr[x-1][y-1]<<endl;
        }
    }
    return 0;
}