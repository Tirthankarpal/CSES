#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    string str,ptr;
    cin>>str>>ptr;
    vector<int> lps(ptr.length(),0);
    int i=1,j=0;
    while(i<ptr.length()){
        if (ptr[i]==ptr[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if (j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    int count = 0;
    while(i<str.length()){
        if (ptr[j]==str[i]){
            i++;
            j++;
        }
        if (j==ptr.length()){
            count++;
            j=lps[j-1];
        }
        else{
            if (i<str.length() && ptr[j]!=str[i]){
                if (j!=0) j=lps[j-1];
                else i++;
            }
        }
    }
    cout<<count<<endl;
}