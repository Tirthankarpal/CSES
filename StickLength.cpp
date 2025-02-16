#include "bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> sticks(n);
    for (int i=0;i<n;i++) {
        cin>>sticks[i];
    }
    sort(sticks.begin(),sticks.end());
    int median=sticks[n/2];
    long long res=0;
    for (int i = 0; i < n; i++) {
        res+=abs(sticks[i]-median);
    }
    cout<<res<<endl;
    return 0;
}