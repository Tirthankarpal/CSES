#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    multiset<ll> a;
    multiset<ll> b;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
        ll sum=0;
        for(ll s=0;s<k;s++){
            b.insert(arr[s]);
            sum+=arr[s];
        }
        ll sumA=0;
        ll sumB=0;
        for(ll s=0;s<(ll)ceil((double)k/2);s++){
            auto it=b.begin();
            sumA+=*it;
            a.insert(*it);
            b.erase(it);
        }
        sumB=sum-sumA;
        ll i=0;
        ll j=k;
        cout<<((((*a.rbegin()))*(a.size())-sumA)+(sumB-((*a.rbegin()))*b.size()))<<" ";
        while(j<n){
            if(arr[j]<=*a.rbegin()){
                if(a.find(arr[i])!=a.end()){
                    sumA+=arr[j];
                    sumA-=arr[i];
                    a.erase(a.find(arr[i]));
                    a.insert(arr[j]);
                }
                else{
                    sumA+=arr[j];
                    sumB-=arr[i];
                    sumB+=*a.rbegin();
                    sumA-=*a.rbegin();
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
                    sumA-=arr[i];
                    sumB+=arr[j];
                    sumA+=*it;
                    sumB-=*it;
                    a.insert(*it);
                    b.erase(it);
                }
                else{
                    b.erase(b.find(arr[i]));
                    b.insert(arr[j]);
                    sumB+=arr[j];
                    sumB-=arr[i];
                }
            }
            i++;
            j++;
            cout<<((((*a.rbegin()))*(a.size())-sumA)+(sumB-((*a.rbegin()))*b.size()))<<" ";
        }
}