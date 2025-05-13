#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        double m1=(y2-y1)/(x2-x1);
        double m2=(y4-y3)/(x4-x3);
        if(m1!=m2){
            cout<<"YES"<<endl;
        }
        else{
            if(y3-y1==m1*(x3-x1)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}