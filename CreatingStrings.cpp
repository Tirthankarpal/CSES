#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
set<string> st;
void back(int idx,string s,string ans,vector<int> &flag){
    if(idx>=s.length()){
        st.insert(ans);
    }
    for(int i=0;i<s.length();i++){
        if(flag[i]==0){
            flag[i]=1;
            back(idx+1,s,ans+s[i],flag);
            flag[i]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<int> flag(s.length(),0);
    back(0,s,"",flag);
    cout<<st.size()<<endl;
    for(auto it:st){
        cout<<it<<endl;
    }
}