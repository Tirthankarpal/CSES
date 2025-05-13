#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n,k;
        cin>>n>>k;
        queue<long long> q;
        for(long long i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>0){
            q.push(q.front());
            q.pop();
            if(k==1){
                cout<<q.front()<<endl;
                break;
            }
            q.pop();
            k--;
        }
    }
}