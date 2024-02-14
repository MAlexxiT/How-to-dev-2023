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
    bool estaOrdenado;
    vector<int> arreglo;
    cin>>n;

    while(arreglo.size()<n){
        cin>>elemento;
        arreglo.push_back(elemento);
    }
    
    estaOrdenado = false;
    while(estaOrdenado == false){
        //inicia en 1 porque 0 no tiene antecesor
        for(int i = 1; i<arreglo.size(); i++){
            //si un numero es menor a su antecesor entonces debe de ser eliminado
            if(arreglo[i]<arreglo[i-1]){
                arreglo = eliminar(arreglo,i);
                //como el numero en la posicion i fue eliminado, se tiene que volver a checar ese elemento, por lo que es necesario decrementar a i
                i--;
            }
        }
        //esta ordenado hasta que se demuestre lo contrario
        estaOrdenado = true;
        for(int i = 1; i<arreglo.size(); i++){
            //si un elemento es menor a su antecesor, entonces el arreglo no esta ordenado
            if(arreglo[i]<arreglo[i-1]){
                estaOrdenado = false;
                break;
            }
        }
    }

    bool primero = true;
    for(int el: arreglo){
        //Imprime el espacio solo si el elemento no es el primero en ser impreso
        if(primero){
            primero = false;
        }else{
            cout<<" ";
        }
        //imprime cada elemento del arreglo
        cout<<el;
    }
    cout<<endl;
}   
//--------------------EOSOLUTION---------------------------------