#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,int from,int to,int aux,vector<pair<int,int> > &towers){
    if (n == 0) {
        return;
    }
    towerOfHanoi(n-1,from,aux,to,towers);
    towers.push_back(make_pair(from,to));
    towerOfHanoi(n-1,aux,to,from,towers);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > towers;
    towerOfHanoi(n,1,3,2,towers);
    cout<<towers.size()<<endl;
    for(auto tower:towers){
        cout<<tower.first<<" "<<tower.second<<endl;
    }
    return 0;
}
