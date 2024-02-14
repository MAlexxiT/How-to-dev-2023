#include "bits/stdc++.h"

using namespace std;
#define endl '\n'


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long int n,res = 0;
    cin>>n;
    while(n){
        res*=10LL;
        res+=(n%10);
        n/=10;
    }
    cout<<res<<endl;
}