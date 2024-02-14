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



//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	long long int n,r,d,e;
	long long int res, tot,f;
	map<long long int, long long int> ocurr;
	cin>>n>>r>>d;
	while(n--){
		cin>>e;
		ocurr[e]++;
	}
	//cout<<fib(0)<<" "<<fib(1)<<" "<<fib(2)<<" "<<fib(3);
	//f(2) = 1, f(3) = 2
	f = 2;
	res =0; tot = 0;
	while(tot<r){
		tot = 0;
		for(pair<long long int, long long int> el: ocurr){
			tot+=el.second*fib(f);
		}

		for(pair<long long int, long long int> el: ocurr){
			if(tot>=r){
				break;
			}
			tot-=el.second*fib(f);
			tot+=el.second*fib(f+1);
			res = (f-2LL)*d + el.first;
		}
		if(tot>=r){
			break;
		}
		f++;
	}

	//cout<<f<<endl;
	cout<<res<<endl;
}
//--------------------EOSOLUTION---------------------------------