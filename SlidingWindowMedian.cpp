#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    multiset<int> a;
    multiset<int> b;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
        for(int s=0;s<k;s++){
            b.insert(arr[s]);
        }
        for(int s=0;s<(int)ceil((double)k/2);s++){
            auto it=b.begin();
            a.insert(*it);
            b.erase(it);
        }
        int i=0;
        int j=k;
        cout<<*a.rbegin()<<" ";
        while(j<n){
            if(arr[j]<=*a.rbegin()){
                if(a.find(arr[i])!=a.end()){
                    a.erase(a.find(arr[i]));
                    a.insert(arr[j]);
                }
                else{
                    b.erase(b.find(arr[i]));
                    a.insert(arr[j]);
                    b.insert(*a.rbegin());
                    a.erase(a.find(*a.rbegin()));
                }
            }
            else{
                if(a.find(arr[i])!=a.end()){
                    a.erase(a.find(arr[i]));
                    b.insert(arr[j]);
                    auto it=b.begin();
                    a.insert(*it);
                    b.erase(it);
                }
                else{
                    b.erase(b.find(arr[i]));
                    b.insert(arr[j]);
                }
            }
            i++;
            j++;
            cout<<*a.rbegin()<<" ";
        }
}