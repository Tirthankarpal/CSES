#include "bits/stdc++.h"
using namespace std;
// #include <bits/stdc++.h>
map<long long, long long> fibo;
long long fib(long long n) {
    if (fibo.count(n)) return fibo[n];
    if(n%2==0){
        return fibo[n]=(fib(n/2)*fib(n/2)+fib(n/2-1)*fib(n/2-1))%1000000007;
    }
    else{
        return fibo[n]=(fib(n/2)*fib(n/2+1)+fib(n/2-1)*fib(n/2))%1000000007;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    fibo[0]=1;
    fibo[1]=1;
    cin>>n;
    cout<<(n==0 ? 0 : fib(n-1))<<endl;
}