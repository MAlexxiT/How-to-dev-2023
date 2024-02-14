#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

vector<int> eliminar(vector<int>arr,int pos){
    vector<int> aux;
    for(int i = 0; i<arr.size(); i++){
        if(i==pos){
            continue;
        }
        aux.push_back(arr[i]);
    }
    return aux;
}
//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,elemento;
    vector<int> arreglo;
    cin>>n;

    while(arreglo.size()<n){
        cin>>elemento;
        arreglo.push_back(elemento);
    }
    int valorMax = arreglo[0];
    bool primero = true;
    for(int el: arreglo){
        if(el>=valorMax){
            if(primero == true){
                primero = false;
            }else{
                cout<<" ";
            }
            valorMax = el;
            cout<<el;
        }
    }
    cout<<endl;
}   
//--------------------EOSOLUTION---------------------------------