#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

//esta solucion en particular puede dar TLE si los vectores son declarados dentro de cada solve
vector<int> a,b;
int n,k;
vector<int> nuevoA,nuevoB;
long long int solve(int mascaraA, int mascaraB){
	nuevoA.clear();nuevoB.clear();
	//genera subconjunto A
	for(int i = 0; i<n; i++){
        //si el bit actual esta encendido, meter el elemento que representa al subconjunto actual
		if(mascaraA%2==1){
			nuevoA.push_back(a[i]);
		}
        //recorrer la mascara un bit a la derecha para continuar con la siguiente posicion
		mascaraA>>=1;
	}
 
    //genera subconjunto B
	for(int i = 0; i<n; i++){
        //si el bit actual esta encendido, meter el elemento que representa al subconjunto actual
		if(mascaraB%2==1){
			nuevoB.push_back(b[i]);
		}
        //recorrer la mascara un bit a la derecha para continuar con la siguiente posicion
		mascaraB>>=1;
	}
    
    //calcula el resultado
	long long int resultado = 0;
	for(int i = 0; i<k; i++){
		resultado+=abs(nuevoA[i]-nuevoB[i]);
	}
 
	return resultado;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int elemento;
	cin>>n>>k;
    
    //lee los contenidos de A
	while(a.size()<n){
		cin>>elemento;
		a.push_back(elemento);
	}
    
    //lee los contenidos de B
	while(b.size()<n){
		cin>>elemento;
		b.push_back(elemento);
	}
 
    //todas las combinaciones involucrando n elementos pueden ser mapeadas de forma unica usando una 
    //mascara de bits en el rango [0-2**n)
	int upp = pow(2,n);
	vector<int> mascaras;
	for(int i = 0; i<upp; i++){
        //si la mascara actual tiene k bits, significa que representa un estado de una cinta con k elementos, por lo que se guarda
		if(__builtin_popcount(i)==k){
			mascaras.push_back(i);
		}
	}

    //se inicializa el resultado con un valor inobtenible
	long long int resultado = 100000000000LL;
	for(int mascaraA: mascaras){
		for(int mascaraB: mascaras){
			resultado = min(resultado,solve(mascaraA,mascaraB));
		}
	}
	cout<<resultado<<endl;
}
//--------------------EOSOLUTION---------------------------------
