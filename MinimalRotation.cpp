#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    priority_queue<string> pq;
    for(int i=1;i<str.length();i++){
        string temp=str.substr(i)+str.substr(0,i);
        pq.push(temp);
        if(pq.size()>1){
            pq.pop();
        }
    }
    cout<<pq.top()<<endl;
}