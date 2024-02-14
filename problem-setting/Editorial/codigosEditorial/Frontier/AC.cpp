#include "bits/stdc++.h"
using namespace std;
#define endl '\n'

//Por defecto todos son falso
bitset<256> palDer;
bitset<256> palIzq;

int contarVertTot(string s){
	int res = 0;
	for(char l: s){
		if(l!=' '){
			if(palDer[l]){
				res++;
			}   
            //evita contar la linea vertical de la I dos veces
			if(l=='I'){
				continue;
			}
			if(palIzq[l]){
				res++;
			}
		}
	}
	return res;
}
int contarVertVis(string s){
    //se agrega un espacio al final para generalizar la logica (no tratar con el caso especial del ultimo caracter)
	s+=' ';
    //se inicializa el resultado dependiendo si la primera letra tiene una linea vertical o no.
	int res = (palIzq[s[0]]?1:0);
 
	for(int i = 1; i<s.size(); i++){
        //Si la letra anterior tiene una linea derecha,la actual una izquierda
        //y si la letra anterior no es I (para evitar contar doble)
		if((palDer[s[i-1]]||palIzq[s[i]]) && s[i-1]!='I'){
			res++;
		}
	}
 
	return res;	
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //se enlistan todos los que tienen palo izquierdo;
	palIzq['A'] = 1;palIzq['B'] = 1;palIzq['C'] = 1;palIzq['D'] = 1;palIzq['E'] = 1;palIzq['F'] = 1;palIzq['G'] = 1;palIzq['H'] = 1;palIzq['I'] = 1;palIzq['K'] = 1;palIzq['L'] = 1;palIzq['M'] = 1;palIzq['N'] = 1;palIzq['O'] = 1;palIzq['P'] = 1;palIzq['Q'] = 1;palIzq['R'] = 1;palIzq['T'] = 1;palIzq['U'] = 1;palIzq['W'] = 1;
	//se enlistan las que tienen palo derecho
	palDer['A'] = 1;palDer['H'] = 1;palDer['I'] = 1;palDer['J'] = 1;palDer['M'] = 1;palDer['N'] = 1;palDer['O'] = 1;palDer['U'] = 1;palDer['V'] = 1;palDer['W'] = 1; 	
	int n;
	int tvl,vvl;
	string s;
	
    //si se mezclan cin con getline, es necesario poner cin.ignore() por cada cin
	cin>>n;cin.ignore();
	
	while(n--){
		getline(cin,s);
		tvl = contarVertTot(s);
		vvl = contarVertVis(s);
		cout<<tvl-vvl<<endl;
	}
    
}
//--------------------EOSOLUTION---------------------------------
