#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int numero;
    int resultado = 0;
    cin>>numero;

    while(numero>0){
        resultado*=10;
        resultado+=numero%10;
        numero/=10;
    }
    cout<<resultado<<endl;
}