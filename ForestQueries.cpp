#include"bits/stdc++.h"
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > arr(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='*')arr[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]+=arr[i-1][j]-arr[i-1][j-1]+arr[i][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<arr[c][d]-arr[a-1][d]-arr[c][b-1]+arr[a-1][b-1]<<endl;
    }
}