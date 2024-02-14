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
unsigned long long int ceilFraccion(unsigned long long int numerador, unsigned long long int denominador) {
	return (numerador + denominador - 1) / denominador;
}
unsigned long long int fib(int n){
	unsigned long long int a = 1,b = 1,aux;
	if(n<=2){
		return 1;
	}
	for(int i = 3; i<=n; i++){
		aux = a+b;
		a = b;
		b = aux;
	}
	return b;
}


unsigned long long int DCLOCK;
map<unsigned long long int, unsigned long long int> bacteriaCount; 
unsigned long long int calcular(unsigned long long int Days){
	unsigned long long int res = 0;
	for(pair<unsigned long long int, unsigned long long int> el: bacteriaCount){
		//cout<<fib(0)<<" "<<fib(1)<<" "<<fib(2)<<" "<<fib(3);
		//f(0) = 0, f(1) = 1, f(2) = 1, f(3) = 2
		if(el.first <= Days%DCLOCK || Days == 0){
			res+=fib((Days/DCLOCK)+3)*el.second;
		}else{
			res+=fib((Days/DCLOCK)+2)*el.second;
		}
	}
	return res;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unsigned long long int N,REQUIRED;
	cin>>N>>REQUIRED>>DCLOCK;
	unsigned long long int e;
	for(int i = 0; i<N; i++){
		cin>>e;
		e--;
		bacteriaCount[e]++;
	}

	unsigned long long int l = 0, r = DCLOCK*70+20,m;

	while((r-l) > 15){
		m = l+r; m/=2ULL;
		if(calcular(m)<REQUIRED){
			l = m+1;
		}else{
			r = m;
		}
	}

	for(unsigned long long int i = l; i<=r; i++){
		if(calcular(i)>=REQUIRED){
			cout<<(i==0?i:i+1)<<endl;
			break;
		}
	}
    
}
//--------------------EOSOLUTION---------------------------------