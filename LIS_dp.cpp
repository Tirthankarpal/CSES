#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    set<ll> s;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        auto it=s.lower_bound(num);
        if(it!=s.end()){
            s.erase(it);
            s.insert(num);
        }
        else{
            s.insert(num);
        }
    }
    cout<<s.size();
    return 0;
}