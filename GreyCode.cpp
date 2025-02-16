#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<pow(2,n);i++){
        int num=i^(i>>1);
        bitset<32> binary(num);
        string binaryStr = binary.to_string();
        cout<<binaryStr.substr(32-n)<<endl;
    }
}