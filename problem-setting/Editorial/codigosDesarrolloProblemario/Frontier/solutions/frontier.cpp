#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;
//Por defecto todos son falso
bitset<256> palDer;
bitset<256> palIzq;
//Por alguna razon mi editor de codigo piensa que la linea 17 es un error pero el codigo compila, si alguien descrubre que es agradeceria un heads-up

int contarVertTot(string s){
	int res = 0;
	for(char l: s){
		if(l!=' '){
			if(palDer[l]){
				res++;
			}
			
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
	s+=' ';
	int res = (palIzq[s[0]]?1:0);

	for(int i = 1; i<s.size(); i++){
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
	
	cin>>n;cin.ignore();
	
	while(n--){
		getline(cin,s);
		tvl = contarVertTot(s);
		vvl = contarVertVis(s);
		cout<<tvl-vvl<<endl;
	}
    
}
//--------------------EOSOLUTION---------------------------------