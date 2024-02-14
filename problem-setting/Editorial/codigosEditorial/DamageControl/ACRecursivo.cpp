#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

vector<int> a,b;
int n,k;
vector<int> nuevoA,nuevoB;
long long int respuesta;


void generaB(int pos){
    //si ya no quedan items en B por considerar
    if(pos==n){
        //si en el subconjunto de B que tomamos hay exactamente 'k' elementos
        //calculamos la respuesta para esta combinacion subconjunto A + subconjunto B
		if(nuevoB.size() == k){
            long long int actual = 0;
            for(int i = 0; i<k; i++){
				actual+=abs(nuevoA[i]-nuevoB[i]);
			}
			respuesta = min(respuesta,actual);
		}
		return;
	}
    //si el tamano del subconjunto B alcanzo a 'k', termina de buscar mas posibilidades y calcula la respuesta para esta combinacion
	if(nuevoB.size() == k){
		long long int actual = 0;
        for(int i = 0; i<k; i++){
			actual+=abs(nuevoA[i]-nuevoB[i]);
		}
		respuesta = min(respuesta,actual);
		return;
	}
    //agrega un elemento al subconjnto actual, genera mas posibilidades
	nuevoB.push_back(b[pos]);
	generaB(pos+1);
    //genera las demas posibilidades sin ese elemento
	nuevoB.pop_back();
	generaB(pos+1);
	return;
}
void generaA(int pos){
    //si ya no quedan items en A por considerar
    if(pos==n){
        //si en el subconjunto de A que tomamos hay exactamente 'k' elementos, generamos los posibles subconjuntos de b
		if(nuevoA.size() == k){
			generaB(0);
		}
		return;
	}
    //si el tamano del subconjunto A alcanzo a 'k', termina de buscar mas posibilidades y  genera los posibles subconjuntos de b
	if(nuevoA.size() == k){
		generaB(0);
		return;
	}
    //agrega un elemento al subconjnto actual, genera mas posibilidades
	nuevoA.push_back(a[pos]);
	generaA(pos+1);
    //genera las demas posibilidades sin ese elemento
	nuevoA.pop_back();
	generaA(pos+1);
	return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    int elemento;
    //lee los elementos en la cinta a
    while(a.size()<n){
        cin>>elemento;
        a.push_back(elemento);
    }
    //lee los elementos en la cinta b
    while(b.size()<n){
        cin>>elemento;
        b.push_back(elemento);
    }
    //se inicializa en un valor inobtenible
    respuesta = 100000000000LL;

    //Genera todas las combinaciones de A y B
    generaA(0);
    cout<<respuesta<<endl;

}