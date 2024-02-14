#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'

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
 
unsigned long long int D;
map<unsigned long long int, unsigned long long int> bacteriaCount; 


unsigned long long int calcular(unsigned long long int milisegundos){
    unsigned long long int res = 0;
    if(milisegundos == 0){
        for(pair<unsigned long long int, unsigned long long int> el: bacteriaCount){
            res+=el.second;
        }
        return res;
    }
	
	for(pair<unsigned long long int, unsigned long long int> el: bacteriaCount){
		//f(0) = 0, f(1) = 1, f(2) = 1, f(3) = 2
		if(el.first <= milisegundos%D){
            //para evitar hacer el procedimiento por cada bacteria con timer inicial en el.first 
            //se multiplica el de una sola bacteria
			res+=fib((milisegundos/D)+3)*el.second;
		}else{
            //para evitar hacer el procedimiento por cada bacteria con timer inicial en el.first 
            //se multiplica el de una sola bacteria
			res+=fib((milisegundos/D)+2)*el.second;
		}
	}
	return res;
}
//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unsigned long long int n, necesarias;
	cin>>n>>necesarias>>D;
	unsigned long long int e;
	for(int i = 0; i<n; i++){
		cin>>e;
		bacteriaCount[e]++;
	}
    

	unsigned long long int l = 0,m;
    //fib(70) es aproximadamente 10**14, en el peor de los casos, si nos dan una sola bacteria y se necesitan 10**13
    //esta garantizado que no tomara mas de D*70 dias
    unsigned long long int r = D*70;
 
	while(r>l){
		m = l+r; m/=2ULL;
		if(calcular(m)<necesarias){
			l = m+1;
		}else{
			r = m;
		}
	}
    cout<<r<<endl;
}
//--------------------EOSOLUTION---------------------------------