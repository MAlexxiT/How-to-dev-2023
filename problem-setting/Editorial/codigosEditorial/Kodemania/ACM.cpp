#include "bits/stdc++.h"

using namespace std;
#define endl '\n'

bool esValida(char letra){
    if(letra == 'k') return true;
    if(letra == 'o') return true;
    if(letra == 'd') return true;
    if(letra == 'e') return true;
    if(letra == 'm') return true;
    if(letra == 'a') return true;
    if(letra == 'n') return true;
    if(letra == 'i') return true;
    if(letra == 'a') return true;
    if(letra == 'K') return true;
    if(letra == 'O') return true;
    if(letra == 'D') return true;
    if(letra == 'E') return true;
    if(letra == 'M') return true;
    if(letra == 'A') return true;
    if(letra == 'N') return true;
    if(letra == 'I') return true;
    if(letra == 'A') return true;
    if(letra == '2') return true;
    if(letra == '0') return true;
    if(letra == '3') return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    char letra;
    cin>>letra;
    cout<<(esValida(letra)?"YES":"NO")<<endl;
}