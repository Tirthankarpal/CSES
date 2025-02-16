#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,n;
    cin>>x>>n;
    set<int> st;
    multiset<int> len;
    st.insert(0);
    st.insert(x);
    len.insert(x);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        auto it=st.lower_bound(m);
        int r=*it;
        --it;
        int l=*it;
        auto it2=len.find(r-l);
        len.erase(it2);
        len.insert(m-l);
        len.insert(r-m);
        st.insert(m);
        cout<<*len.rbegin()<<" ";
    }
}