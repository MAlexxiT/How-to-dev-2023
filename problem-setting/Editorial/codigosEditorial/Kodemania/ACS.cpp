#include "bits/stdc++.h"

using namespace std;
#define endl '\n'

bool esValida(char letra){
    string s = "KODEMANIAkodemania2023";
    for(char l: s){
        if(l== letra) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    char letra;
    cin>>letra;
    cout<<(esValida(letra)?"YES":"NO")<<endl;
}